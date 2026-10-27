#include <iostream>
#include <thread>
#include <chrono>
#include <numbers>

using std::cout;

int main() {
    using namespace std::chrono_literals;
    cout << "==== welcome to the circle perimeter finder ====\n"
            "enter radius:\n";
    double radiusInput{};
    if (!(std::cin >> radiusInput) || radiusInput < 0) {
        std::cerr << "invalid input, try again.\n";
        return 1;
    }

    auto perimeterFinder = [](const double radius) {
        return 2 * std::numbers::pi * radius;
    };

    cout << "The circle perimeter is: "
         << perimeterFinder(radiusInput) << '\n';

    return 0;
}