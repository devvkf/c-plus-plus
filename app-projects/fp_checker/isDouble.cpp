#include <iostream>
#include <concepts>
#include <cmath>
#include <stdexcept>
#include <string>

using std::cout;

template <typename D>
concept isDouble = std::same_as<D, double>;

template <isDouble D>
static void checkValue(D value)
{
    cout << "Passed: " << value << '\n';
}

static bool is_decimal_string(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    std::size_t parsed{};
    try {
        const double value = std::stod(str, &parsed);
        return parsed == str.size() && std::isfinite(value);
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

int main() {
    cout << "==== float checker ====\n"
            "value to check:\n";
    std::string input;
    if (!(std::cin >> input)) {
        cout << "error: invalid input.\n";
        return 1;
    }

    if (is_decimal_string(input)) {
        const double valueToCheck = std::stod(input);
        checkValue(valueToCheck);
    }
    else {
        cout << "error: not a decimal number.\n";
    }
}