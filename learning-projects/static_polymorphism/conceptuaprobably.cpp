#include <concepts>
#include <iostream>
#include <string>

using str = std::string;
using std::cout;
template <typename Q>
concept isString = std::same_as<Q, str>;

void process(const isString auto& str) {
    cout << "str: " << str << '\n';
}

void process(const auto& notStr) {
    cout << "not a string\n";
}

int main() {
    str name = "Devlyn";
    int age = 19;

    process(name);
    process(age);
}