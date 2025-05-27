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
     complex(double r = 0,double i = 0){
         Re = r;
         Im = i;
     }

    // 一些计算用的函数
    double real() const { // const成员函数可以给const和!const用，但!const只能给!const用
        return Re;
    }
    double imag() const {
        return Im;
    }
    double mod() const{
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
};
complex& complex::operator*=(complex z) {
    double ans_re = Re * z.Re - Im * z.Im;
    double ans_im = Im * z.Re + Re * z.Im;
    Re = ans_re;
    Im = ans_im;
    return *this;
}
complex& complex::operator/=(complex z) {
    double temp = z.mod()*z.mod();
    double ans_re = (Re * z.Re + Im * z.Im) / temp;
    double ans_im = (Im * z.Re - Re * z.Im) / temp;
    Re = ans_re;
    Im = ans_im;
    return *this;
}

int main() {
    complex num1(1, 2);
    complex num2(2, 2);
    num1 *= num2;
    std::cout << num1.mod() << std::endl;
}