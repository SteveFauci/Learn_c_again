#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> s;

    char ch;
    int  flag = 0;

    while (cin.get(ch)) {
        if (ch == '\n')
            break;
        if (ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        if (ch == ')' || ch == ']' || ch == '}') {
            char temp;
            if (s.empty())
                flag = 1;
            else {
                temp = s.top();
                s.pop();
                if ((ch == '}' && temp != '{') || (ch == ']' && temp != '[') ||
                    (ch == ')' && temp != '('))
                    flag = 1;
            }
        }
    }
    if (!s.empty()) {
        flag = 1;
    }
    cout << (flag ? "NO\n" : "YES\n");
}
