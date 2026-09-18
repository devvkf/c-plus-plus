#include <iostream>
#include <concepts>
#include <cstdint>

template<typename D>
concept bigInteger = std::integral<D> && (sizeof(D) >= 4);

static void handle(bigInteger auto x) {
    std::cout << "process: " << x << '\n';
}

int main() {
    int8_t d = 5;
    int32_t e = 152;

    handle(e);
}