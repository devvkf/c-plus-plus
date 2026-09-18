#include <iostream>
#include <concepts>

static void processNumber(std::integral auto d){
    std::cout << "Integer: " << d << '\n';
}

static void processNumber(std::floating_point auto d) {
    std::cout << "Float: " << d << '\n';
}

int main() {
    processNumber(3.14);
    processNumber(-3);

    return 0;
}