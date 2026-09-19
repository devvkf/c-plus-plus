#include <iostream>
#include <concepts>

using std::cout;

template <typename D>
concept isDouble = std::same_as<D, double>;

template <isDouble D>
static void checkValue(D value)
{
    cout << "Passed: " << value << '\n';
}

int main() {
    cout << "==== float checker ====\n"
            "value to check:\n";
    double valueToCheck{};
    std::cin >> valueToCheck;

    if (std::cin >> valueToCheck) {
        checkValue(valueToCheck);
    }
    else {
        cout << "error: invalid input, not a double.\n";
    }
}