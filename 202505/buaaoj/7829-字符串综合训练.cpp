#include <iostream>
#include <string>
using namespace std;
string str2;
string str1;
int    i;
int    j;
void   operation(int op) {
    switch (op) {
    case 1:
        cin >> ws >> str2; // ws 显式跳过空白字符
        str1 += str2;
        break;
    case 2:
        cin >> i;
        str1.erase(i);
        break;
    case 3:
        cin >> i >> ws >> str2;
        str1.insert(i + 1, str2);
        break;
    case 4:
        cin >> i >> j;
        str1.erase(i, j - i + 1);
        break;
    case 5:
        cin >> i >> j >> ws >> str2;
        str1.erase(i, j - i + 1);
        str1.insert(i, str2);
        break;
    case 6:
        cin >> ws >> str2;
        if (str1.find(str2) == string::npos) {
            cout << "NULL" << endl;
        } else {
            cout << str1.find(str2) << " " << str1.rfind(str2) << endl;
        }
    }
}
int main() {
    getline(cin, str1);
    int op;
    while (cin >> op) {
        operation(op);
//      cout << str1 << endl;
    }
    cout << str1 << endl;
}