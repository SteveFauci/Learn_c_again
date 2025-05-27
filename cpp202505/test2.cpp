#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Person {
  private:
    string name;
    int    age;

  public:
    Person(string n, int a) : name(n), age(a) {
    }
    void printInfo() {
        cout << "Print: " + name + " " << age << endl;
    }
};

int main() {
    Person p("Bob", 30);
    p.printInfo();
}
