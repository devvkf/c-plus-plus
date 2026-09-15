// pass if grade >= 73, else fail
// condition ? result1 : result2

#include <iostream>
#include <thread>
#include <chrono>

using std::cout;

int main() {
    using namespace std::chrono_literals;
    auto gradeChecker = [](const int inputGrade) {
        inputGrade >= 73 ? cout << inputGrade << ": You pass!\n" : cout << inputGrade << ": You failed...\n";
    };

    cout << "enter your grade to evaluate:\n";
    int inputGrade{};
    while (!(std::cin >> inputGrade)) {
        std::cerr << "invalid input. try again.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    cout << "getting input...\n";
    std::this_thread::sleep_for(10ms);
    cout << "evaluating grade...\n";
    std::this_thread::sleep_for(600ms);
    cout << "final touches...\n";
    std::this_thread::sleep_for(250ms);

    gradeChecker(inputGrade);

    return 0;
}