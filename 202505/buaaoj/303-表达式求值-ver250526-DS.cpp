#include <cmath>
#include <iostream>
#include <stack>
#include <stdexcept>

class ExpressionCalculator {
public:
    double calculate(const std::string& expression) {
        // 重置状态
        clearStacks();
        
        // 处理表达式
        for (size_t i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            char pre_ch = (i > 0) ? expression[i-1] : '\0';

            // 处理数字
            if (isdigit(ch) || ch == '.') {
                number += ch;
                continue;
            } else {
                if (!number.empty()) {
                    num.push(stod(number));
                    number.clear();
                }
            }

            // 处理运算符和括号
            if (ch == '-' && (pre_ch == '(' || isOperator(pre_ch) || i == 0)) {
                op.push('#'); // 一元负号
            } 
            else if (isOperator(ch)) {
                while (!op.empty() && op.top() != '(' && precedence(ch) <= precedence(op.top())) {
                    compute();
                }
                op.push(ch);
            } 
            else if (ch == '(') {
                op.push(ch);
            } 
            else if (ch == ')') {
                while (!op.empty() && op.top() != '(') {
                    compute();
                }
                if (op.empty()) {
                    throw std::runtime_error("Mismatched parentheses");
                }
                op.pop(); // 弹出 '('
            }
            // 忽略其他字符（如空格等）
        }

        // 处理最后一个数字
        if (!number.empty()) {
            num.push(stod(number));
            number.clear();
        }

        // 计算剩余操作
        while (!op.empty()) {
            compute();
        }

        if (num.size() != 1) {
            throw std::runtime_error("Invalid expression");
        }

        double result = num.top();
        clearStacks();
        return result;
    }

private:
    std::stack<char> op;       // 操作符栈
    std::stack<double> num;    // 数字栈
    std::string number;        // 临时存储数字字符串

    void clearStacks() {
        while (!num.empty()) num.pop();
        while (!op.empty()) op.pop();
        number.clear();
    }

    double computeOperation(double num1, double num2, char oper) {
        switch (oper) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': 
                if (num2 == 0) throw std::runtime_error("Division by zero");
                return num1 / num2;
            case '^': return pow(num1, num2);
            case '#': return -num2; // 一元负号
            default: throw std::runtime_error("Unknown operator");
        }
    }

    void compute() {
        if (op.empty() || num.empty()) return;
        
        char oper = op.top();
        op.pop();
        
        if (oper == '#') {
            if (num.empty()) throw std::runtime_error("Invalid expression");
            double num2 = num.top();
            num.pop();
            num.push(computeOperation(0, num2, oper));
            return;
        }

        if (num.size() < 2) throw std::runtime_error("Invalid expression");
        double num2 = num.top(); num.pop();
        double num1 = num.top(); num.pop();
        num.push(computeOperation(num1, num2, oper));
    }

    int precedence(char op) const {
        switch (op) {
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            case '^': case '#': return 3;
            default: return 0;
        }
    }

    bool isOperator(char ch) const {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
};

int main() {
    ExpressionCalculator calculator;
    std::string expression;
    
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);
    
    try {
        double result = calculator.calculate(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}