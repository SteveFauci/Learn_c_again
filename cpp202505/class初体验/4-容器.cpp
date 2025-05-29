#include <algorithm>
#include <initializer_list>
class Vector {
  public:
    Vector(int s) : elem{new double[s]}, sz{s} { // 初始化列表
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }
    // Vector(int s){
    //     elem = new double[s];
    //     sz = s;
    //     for(int i=0;i<s;i++){
    //         elem[i]=0;
    //     }
    // }
    Vector(std::initializer_list<int>);
    double& operator[](int i) {
        return elem[i];
    }

  private:
    double* elem;
    int     sz;
};
Vector::Vector(std::initializer_list<int> lst)
    : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
}