// result = HelloWorld(print)

#include <iostream>

using str = std::string;
using std::cout;
static void HelloWorld(const str& input);

int main() {
    const str print = "print";
    HelloWorld(print);
    return 0;
}

void HelloWorld(const str& input) {
    cout << input << std::endl;
}