#include <iostream>
#include <stack>
double calc(double num1, double num2, char oper) {
    switch (oper) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}
int cmp_op(char current_op, char stack_op) {
    if ((current_op == '*' || current_op == '/') &&
        (stack_op == '+' || stack_op == '-')) {
        return 1;
    } else {
        return 0;
    }
}
using namespace std;
int main() {
    stack<char>   op;
    stack<double> num;
    string        number;

    char ch;
    while (cin.get(ch)) {
        /***是数字，读入数字并入栈***/
        if (isdigit(ch) || ch == '.') {
            number += ch;
        } else {
            if (!number.empty()) {
                num.push(stod(number));
                number.clear();
            }
        }
        // if (!number.empty()) {
        //     num.push(stod(number));
        //     number.clear();
        // }
        /***是符号***/
        /*1.加减*/
        if (ch == '+' || ch == '-') {
            if (op.empty())
                op.push(ch);
            else {
                if (op.top() == '(') {
                    op.push(ch);
                    continue; // 加上了continue
                } else {
                    double num1 = num.top();
                    num.pop();
                    double num2 = num.top();
                    num.pop();
                    char temp = op.top();
                    op.pop();
                    num.push(calc(num2, num1, temp));
                }
                op.push(ch);
            }
        }
        /*2.乘除*/
        if (ch == '*' || ch == '/') {
            if (op.empty())
                op.push(ch);
            else {
                if (op.top() == '(')
                    op.push(ch);
                else {
                    char stack_op = op.top();
                    if (cmp_op(ch, stack_op)) {
                        op.push(ch);
                        continue; // 第二次修加上了continue并取消第90行注释
                    } else {
                        double num1 = num.top();
                        num.pop();
                        double num2 = num.top();
                        num.pop();
                        char temp = op.top();
                        op.pop();
                        num.push(calc(num2, num1, temp));
                    }
                }
                op.push(ch); // 第一次修把这个注释掉了
            }
        }
        /*3.(*/
        if (ch == '(')
            op.push(ch);
        /*4.)*/
        if (ch == ')') {
            while (op.top() != '(') {
                double num1 = num.top();
                num.pop();
                double num2 = num.top();
                num.pop();
                char temp = op.top();
                op.pop();
                num.push(calc(num2, num1, temp));
            }
            op.pop(); // 挖掉剩余的(
        }
        if (ch == '\n')
            break;
    }
    if (!number.empty()) {
        num.push(stod(number));
        number.clear();
    }
    while (!op.empty()) {
        double num1 = num.top();
        num.pop();
        double num2 = num.top();
        num.pop();
        char temp = op.top();
        op.pop();
        num.push(calc(num2, num1, temp));
    }
    cout << num.top() << endl;
   // num.pop();
}

/*
待办：

3. 加入负数
4. 也许要弄一个防除以0
*/