#include <cmath>
#include <iostream>
class complex {
  private:
    double Re, Im;

  public:
    // 各种构造函数：与class同名，没有返回值
    // complex(double r, double i) {
    //     Re = r;
    //     Im = i;
    // }
    // complex(double r) {
    //     Re = r;
    //     Im = 0;
    // }
    // complex() { // 默认构造函数
    //     Re = 0;
    //     Im = 0;
    // }
    // 上面三个可以直接写成
    // complex(double r = 0, double i = 0) {
    //     Re = r;
    //     Im = i;
    // }
    // 成员初始化列表 P27
    complex(double r = 0, double i = 0) : Re{r}, Im{i} {
    }

    // 一些计算用的函数
    double real() const {
        return Re; // const成员函数可以给const和!const用，但!const只能给!const用
    }
    double imag() const {
        return Im;
    }
    double mod() const {
        return sqrt(Re * Re + Im * Im);
    }
    // 运算符重载示例
    complex& operator+=(complex z) {
        Re += z.Re;
        Im += z.Im;
        return *this;
    }
    complex& operator-=(complex z) {
        Re -= z.Re;
        Im -= z.Im;
        return *this;
    }
    // 可以写在class的外面
    complex& operator*=(complex z);
    complex& operator/=(complex z);
    // complex& operator^=(int n);
    // complex& operator^=(complex n);
};
complex& complex::operator*=(complex z) {
    double ans_re = Re * z.Re - Im * z.Im;
    double ans_im = Im * z.Re + Re * z.Im;
    Re = ans_re;
    Im = ans_im;
    return *this;
}
complex& complex::operator/=(complex z) {
    double temp = z.mod() * z.mod();
    double ans_re = (Re * z.Re + Im * z.Im) / temp;
    double ans_im = (Im * z.Re - Re * z.Im) / temp;
    Re = ans_re;
    Im = ans_im;
    return *this;
}
// complex& complex::operator^=(int n){

// }
// complex& complex::operator^=(complex z){

// }
// 下面这些函数不访问complex的private变量，所以说定义可以写在外面，就不用写在类的定义里面了
// clang-format off
complex operator-(complex a, complex b) {return a -= b;}
complex operator-(complex a) {return {-a.real(), -a.imag()};}
complex operator+(complex a, complex b) {return a += b;}
complex operator*(complex a, complex b) {return a *= b;}
complex operator/(complex a, complex b) {return a /= b;}

bool operator==(complex a, complex b) {return (a.real() == b.real() && a.imag() == b.imag());}
bool operator!=(complex a, complex b) {return !(a == b);}
// clang-format on
int main() {
    complex num[10];
    num[0] = {1, 2};
    num[1] = {2, 3};
    num[2] = num[0] * num[1];
    std::cout << num[2].real() << '+' << num[2].imag() << 'i' << std::endl;
}