// result = HelloWorld(print)

#include <iostream>

using str = std::string;
using std::cout;
using std::cin;
static void HelloWorld(const str& input);

int main() {
    cout << "What text to input?\n";
    str print{};
    std::getline(std::cin >> std::ws, print);
    
    HelloWorld(print);
    return 0;
}

void HelloWorld(const str& input) {
    cout << input << std::endl;
}