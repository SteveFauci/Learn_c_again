#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int    a, b;
    double x, y;
    string s1, s2;
    cin >> a >> b >> x >> y >> s1 >> s2;
    cout << a + b << endl;
    cout << fixed << setprecision(3) << x + y << endl;
    cout << s1 + s2 << endl;
}