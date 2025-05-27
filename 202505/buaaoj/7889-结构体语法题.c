#include <stdio.h>
struct Complex {
    long long Re, Im;
};
struct Complex sum(struct Complex a, struct Complex b) {
    struct Complex c;
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;
    return c;
}
struct Complex prod(struct Complex a, struct Complex b) {
    struct Complex c;
    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + a.Im * b.Re;
    return c;
}
struct Complex power(struct Complex a, int k) {
    struct Complex res;
    res.Re = 1;
    res.Im = 0;
    for (int j = 0; j < k; j++) {
        res = prod(res, a);
    }
    return res;
}
int main() {
    struct Complex z[5];
    int            n, m;
    for (int i = 1; i <= 4; i++) {
        scanf("%lld%lld", &z[i].Re, &z[i].Im);
    }
    scanf("%d%d",&n,&m);
    z[0] = power(sum(power(sum(z[1], z[2]), n), prod(z[3], z[4])), m);
    printf("%lld %lld", z[0].Re, z[0].Im);
}
