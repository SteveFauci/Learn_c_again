#include <iostream>
#include <string>
using namespace std;
class student { // struct成员default是public //class成员default是private
    // 把class换成struct 把public去掉就是cpp的结构体
    string     name;
    int        h, m, s, sec;
    char       memo[101];
    static int count; // 对象所有成员*共享*的static变量，要在类的外面进行初始化
    // student(){
    //     name.clear();
    //     h=m=s=sec=0;
    //     memset(memo, 0, sizeof(memo));
    // }
  public:
    student(string name1 = "default", int hh = 0, int mm = 0, int ss = 0) {
        name = name1;
        h = hh;
        m = mm;
        s = ss;
        sec = h * 3600 + m * 60 + s;
        count ++;
    } // 调用student()是创建匿名对象。。

    void show() {
        cout << "name:" + name + " time-" << sec << 's' << endl;
    }
    void show2();
    static void showCount(){//static函数好像只能访问static或全局变量
        cout << "Count: " << count <<endl;
    }
    ~student() {
        cout << "test\n";
        // 一般在这delete掉刚刚new的
        count--;//复原static变量
    }
};
int student::count = 0;
inline void student::show2() { // 加上inline是内联函数
    cout << "name:" + name + " time-" << h << ':' << m << ':' << s << endl;
}
int main() {
    // student stu;//("fauci", 11, 45, 14);
    // stu.setvalue("fauci", 11, 45, 14);
    // student stu()不是声明对象，是声明一个返回值为student的函数
    student* stu = new student;
    stu->show();
    stu->show2();
    student::showCount();
    delete stu;
    student::showCount();
}