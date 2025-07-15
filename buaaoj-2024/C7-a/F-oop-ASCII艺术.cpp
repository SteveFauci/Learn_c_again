#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using base_t = float;

const int H = 25, W = 50, max_sdf_trace = 512;
const base_t eps = 2e-4, inf = 500;

class Vec {
public:
	base_t x, y, z;
	Vec() : x(0), y(0), z(0) {}
	Vec(base_t x, base_t y, base_t z) : x(x), y(y), z(z) {}
	Vec(const Vec &v) : x(v.x), y(v.y), z(v.z) {}
	base_t len() const { return sqrt(x * x + y * y + z * z); }
	Vec norm() const { base_t l = len(); return Vec(x / l, y / l, z / l); }
	friend Vec operator + (const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y, a.z + b.z); }
	friend Vec operator - (const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y, a.z - b.z); }
	friend Vec operator * (const Vec &a, const Vec &b) { return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
	friend base_t operator ^ (const Vec &a, const Vec &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
	friend Vec operator * (base_t k, const Vec &a) { return Vec(k * a.x, k * a.y, k * a.z); }
};

using Point = Vec;
using Image = std::vector<std::vector<Vec>>;

const Point O = Point(0, 0, 0);
const Vec X = Vec(1, 0, 0), Y = Vec(0, 1, 0), Z = Vec(0, 0, 1);

const int C = 10;
char colormap[C + 1] = " @W%x+=-:.";
void printImage(Image &img, const Vec &vec) {
	for (int i = -1; i <= H; i++) {
		printf("%c", i == -1 || i == H ? '+' : '|');
		for (int j = 0, c = 0; j < W; j++, c = 0) {
			if (i == -1 || i == H) { printf("-"); continue; }
			Vec grad = img[i][j];
			base_t v = vec ^ grad;
			if (grad.len() > 0.5) c = ceil((v / 2 + 0.5) * (C - 1));
			if (c >= C) c = C - 1;
			printf("%c", colormap[c]);
		}
		printf("%c\n", i == -1 || i == H ? '+' : '|');
	}
}

class SDF {
public:
	virtual base_t f(Point p) const = 0;
	Vec grad(Point p) const {
		base_t fp = f(p);
		base_t dx = (f(p + eps * X) - fp) / eps;
		base_t dy = (f(p + eps * Y) - fp) / eps;
		base_t dz = (f(p + eps * Z) - fp) / eps;
		return Vec(dx, dy, dz).norm();
	}
	virtual base_t trace(Point ro, Vec rd, base_t max_d) const {
		Point p = ro;
		int cnt = 0;
		while ((p - ro).len() < max_d && p.len() < inf) {
			if (fabs(f(p)) < eps) return (p - ro).len();
			p = p + fabs(f(p)) * rd;
			if (++cnt > max_sdf_trace) return inf;
		}
		return inf;
	}
};

class Scene {
public:
	std::vector<SDF *> obj;
	void append(SDF *sdf) { obj.emplace_back(sdf); }
	Vec trace(Point ro, Vec rd, int cnt = 0) const {
		base_t min_d = inf;
		SDF *o_hit;
		for (auto o : obj) {
			base_t d = o->trace(ro, rd, min_d);
			if (d < min_d) { o_hit = o; min_d = d; }
		}
		if (min_d >= inf) return O;
		Point p = ro + min_d * rd;
		return o_hit->grad(p);
	}
};

class Camera {
public:
	Vec from, to, z;
	base_t pixh, pixw;
	Camera() : from(O), to(X), z(Z), pixh(0.01), pixw(0.005) {}
	Camera(Vec from, Vec to, Vec z, base_t pixh, base_t pixw) : from(from), to(to), z(z.norm()), pixh(pixh), pixw(pixw) {}
	Image render(Scene s) {
		Image img(H);
		Vec r = ((to - from) * z).norm();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				base_t x = i, y = j;
				Vec d = to + (H / 2.0 - x) * pixh * z + (y - W / 2.0) * pixw * r;
				img[i].emplace_back(s.trace(from, (d - from).norm()));
			}
		}
		return img;
	}
};

class Sphere : public SDF { // 以点 o 为球心、半径为 r 的球体
public:
	Point o;
	base_t r;
	Sphere(Point o, base_t r) : o(o), r(r) {}
	base_t f(Point p) const override {
		// 返回值：点 p 与球体表面的距离
		// 返回值为正表示 p 在球体外部，为负表示 p 在球体内部
		// 提示：你可以使用 (p - o).len() 计算点 p 与点 o 之间的距离
		return (p - o).len() - r;
	}
};

class Intersection : public SDF { // 两个物体 obj1 与 obj2 的交
public:
	SDF *obj1, *obj2;
	Intersection(SDF *obj1, SDF *obj2) : obj1(obj1), obj2(obj2) {}
	base_t f(Point p) const override {
		// 返回值：obj1->f(p) 与 obj2->f(p) 的最大值
		return std::max(obj1->f(p),obj2->f(p));
	}
};

class Union : public SDF { // 两个物体 obj1 与 obj2 的并
public:
	SDF *obj1, *obj2;
	Union(SDF *obj1, SDF *obj2) : obj1(obj1), obj2(obj2) {}
	base_t f(Point p) const override {
		// 返回值：obj1->f(p) 与 obj2->f(p) 的最小值
		return std::min(obj1->f(p),obj2->f(p));
	}
};

class Subtraction : public SDF { // 两个物体 obj1 与 obj2 的差
public:
	SDF *obj1, *obj2;
	Subtraction(SDF *obj1, SDF *obj2) : obj1(obj1), obj2(obj2) {}
	base_t f(Point p) const override {
		// 返回值：obj1->f(p) 与 -obj2->f(p) 的最大值
		return std::max(obj1->f(p),-obj2->f(p));
	}
};

int main() {
	int t;
	scanf("%d", &t);
	Scene s;
	switch (t) {
		case 1:
			s.append(new Sphere(O, 1));
			break;
		case 2:
			s.append(new Union(
				new Intersection(new Sphere(Y + Z, 1.8), new Sphere(O - Y - Z, 1.8)),
				new Intersection(new Sphere(Y - Z, 1.8), new Sphere(O - Y + Z, 1.8))
			));
			break;
		case 3:
			s.append(new Subtraction(
				new Intersection(new Sphere(Z, 1.5), new Sphere(O - Z, 1.5)),
				new Intersection(new Sphere(Y, 1.5), new Sphere(O - Y, 1.5))
			));
			break;
		case 4:
			s.append(new Sphere(0.4 * Y + 0.4 * Z, 0.2));
			s.append(new Sphere(O - 0.4 * Y + 0.4 * Z, 0.2));
			s.append(new Subtraction(
				new Sphere(O - 0.1 * Z, 0.6),
				new Union(new Sphere(O - 0.1 * X, 0.6), new Sphere(O + 0.1 * X, 0.6))
			));
			break;
	}

	Camera c(-5 * X, -4 * X, Z, 0.02, 0.01);
	Image img = c.render(s);
	printImage(img, Vec(1, 1, 1).norm());
	return 0;
}