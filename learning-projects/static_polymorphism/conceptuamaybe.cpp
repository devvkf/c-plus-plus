#include <iostream>
#include <concepts>
#include <string>

using namespace std::string_literals;

// CONCEPT: "Type D is valid ONLY IF writing 'a + a' is valid C++ code"
template <typename D>
concept CanAddItself = requires(D a) {
    a + a;
};

// FUNCTION: Duplicates anything that satisfies the concept
auto duplicate(const CanAddItself auto& input) {
    return input + input;
}

int main() {
    std::string text = "hello";
    std::cout << duplicate(text) << '\n';  // Output: hellohello

    int num = 21;
    std::cout << duplicate(num) << '\n';   // Output: 42

    // double_it("hello"s); // Output: hellohello (using C++ string literal)
}