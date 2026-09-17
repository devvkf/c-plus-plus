#include <iostream>
#include <string>

using str = std::string;

template<typename D>
static D add (const D& a, const D& b) {
    return a + b;
}

int main() {
    std::cout << add(5, 6) << '\n';
    std::cout << add(6.5, 3.2) << '\n';
    std::cout << add(str("hello "), str("world"));

    return 0;
}