#include <iostream>
#include <string>
using namespace std;
class student {//struct成员default是public //class成员default是private
  public: // 把class换成struct 把public去掉就是cpp的结构体
    string name;
    int    h, m, s, sec;
    void   setvalue(string name1, int hh, int mm, int ss) {
        name = name1;
        h = hh;
        m = mm;
        s = ss;
        sec = h * 3600 + m * 60 + s;
    }
    void show() {
        cout << "name:" + name + " time-" << sec <<'s'<< endl;
    }
    void show2();
};
inline void student::show2() { //加上inline是内联函数
    cout << "name:" + name + " time-" << h << ':' << m << ':' << s << endl;
}
int main() {
    student stu;
    stu.setvalue("fauci", 11, 45, 14);
    stu.show();
    stu.show2();
}