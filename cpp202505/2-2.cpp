#include <iostream>
struct Vector {
    double* elem;
    int     sz;
};
void Vector_init(Vector& v, int s) {
    v.elem = new double[s]; // v.elem = (double*)malloc(sizeof(double)*s);
    v.sz = s;
}
double read_and_sum(int s) {
    Vector v;
    Vector_init(v, s);
    double sum = 0;
    for (int i = 0; i < s; i++) {
        std::cin >> v.elem[i];
        sum += v.elem[i];
    }
    return sum;
}
int main() {
    Vector v;
    std::cout<<read_and_sum(3);
}