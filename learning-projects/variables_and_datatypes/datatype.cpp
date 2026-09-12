#include <iostream>
#include <string>

using str = std::string;

int main() {
    str x{};
    std::cout << "What is your name?\n";
    std::getline(std::cin >> std::ws, x);
    std::cout << "Hello, " << x << "!\n";
    return 0;
}