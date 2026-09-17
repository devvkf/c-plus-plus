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
    if (!(std::cin >> radiusInput)) {
        std::cerr << "invalid input, try again.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    auto perimeterFinder = [](const double radius) {
        return 2 * std::numbers::pi * radius;
    };

    cout << "getting user input...\n";
    std::this_thread::sleep_for(20ms);
    cout << "calculating...\n";
    std::this_thread::sleep_for(800ms);
    cout << "final touches...\n";
    std::this_thread::sleep_for(300ms);
    std::cerr << "an error ocurred while display, fixing...\n";
    std::this_thread::sleep_for(1500ms);
    std::cerr << "error persistence, fixing again...\n";
    std::this_thread::sleep_for(1500ms);

    for (int i = 0; i < 50; ++i) {
        std::cerr << "dawg\n";
    }

    return 0;
}