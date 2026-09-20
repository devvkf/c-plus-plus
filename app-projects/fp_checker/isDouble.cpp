#include <iostream>
#include <concepts>
#include <string>

using std::cout;

template <typename D>
concept isDouble = std::same_as<D, double>;

template <isDouble D>
static void checkValue(D value)
{
    cout << "Passed: " << value << '\n';
}

bool is_decimal_string(const std::string& str) {
    return str.find('.') != std::string::npos;  // has a decimal point
}

int main() {
    cout << "==== float checker ====\n"
            "value to check:\n";
    std::string input;
    std::cin >> input;

    if (is_decimal_string(input)) {
        double valueToCheck = std::stod(input);
        checkValue(valueToCheck);
    }
    else {
        cout << "error: not a decimal number.\n";
    }
}