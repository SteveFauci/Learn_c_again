#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, sub;
    getline(cin, str1);
    getline(cin, sub);
    size_t pos = 0;
    while ((pos = str1.find(sub, pos)) != string::npos) {
        reverse(str1.begin() + pos, str1.begin() + pos + sub.length());
        pos += sub.length();
    }
    cout << str1 << endl;
    return 0;
}