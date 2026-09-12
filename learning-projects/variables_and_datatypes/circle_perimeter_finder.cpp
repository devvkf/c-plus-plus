#include <iostream>
#include <numbers>

static double getResult(double radius);

int main() {
    double radius{};

    std::cout << "==== Circle Perimeter Calculator ====\n"
                 "Enter the radius of the circle (in cm):\n";

    if (!(std::cin >> radius) || radius < 0) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    std::cout << "The perimeter of the circle is: "
    << getResult(radius) << "cm\n";
    return 0;
}

double getResult(const double radius) {
    return radius * std::numbers::pi * 2;
}