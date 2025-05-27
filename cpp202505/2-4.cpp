#include <iostream>
enum Traffic_light { green, yellow, red };
Traffic_light& operator++(Traffic_light& t) {
    using enum Traffic_light;
    switch (t) {
    case green:
        return t = yellow;
    case yellow:
        return t = red;
    case red:
        return t = green;
    }
}
int main() {
    auto signal = Traffic_light::green;
    for (int i = 0; i < 10; i++) {
        std::cout << signal << std::endl;
        if(signal == Traffic_light::red){
            std::cout <<"stop!\n";
        }if(signal == Traffic_light::green){
            std::cout <<"go!\n";
        }
        ++signal;
    }
}