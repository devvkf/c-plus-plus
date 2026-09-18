#include <iostream>
#include <concepts>

template <typename T>
concept Printable = requires(T x) {
    std::cout << x;
};

void print_it(Printable auto x) {
    std::cout << x << '\n';
}

int main() {
    print_it(42);
    print_it("Devlyn");
}