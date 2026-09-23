#include <iostream>
#include <concepts>
#include <string>

using str = std::string;

template <typename D>
concept isExactType = std::convertible_to<D, str>;

static void process(const isExactType auto& inputValue) {
    std::cout << "Passed!\n";
}

int main() {
    std::cout << "enter string to check:\n";
    str input{};

    if (std::getline(std::cin
         >> std::ws, input)) {
        process(input);
    }
    else {
        std::cerr << "no\n";
    }
}