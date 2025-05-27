#include <iostream>
class Vector {
  private:
    double* elem;
    int     sz;

  public:
    Vector(int s) {
        elem = new double[s];
        sz = s;
    }
    ~Vector() {
        delete elem;
    }
    double read_and_sum() {
        double sum = 0;
        for (int i = 0; i < sz; i++) {
            std::cin >> elem[i];
            sum += elem[i];
        }
        return sum;
    }
    double& operator[](int i) {
        return elem[i];
    }
    int size() {
        return sz;
    }
};
int main() {
    Vector v(3);
    std::cout << v.read_and_sum() << std::endl;
    std::cout << v[1] << std::endl;
    std::cout << v.size() << std::endl;
}