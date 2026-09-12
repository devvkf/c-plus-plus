// A = P(1 + rt)

#include <iostream>
#include <format>
#include <chrono>
#include <string>
#include <thread>

using str = std::string;
using std::cout, std::cin;

str getSimpleInterestResult(double principal_amount,
    double annual_interest_rate, int years_invested);

int main() {
    using namespace std::chrono_literals;

    cout << "==== simple interest calculator ====\n"
            "how much money will you invest? (in $)\n";
    double money_to_invest{};
    if (!(cin >> money_to_invest)) {
        std::cerr << "not a valid integer\n";
        return 1;
    }

    cout << "what's the annual interest rate (in %)?\n";
    double annual_interest_rate{};
    if (!(cin >> annual_interest_rate)) {
        std::cerr << "not a valid interest rate\n";
        return 1;
    }
    annual_interest_rate = annual_interest_rate / 100;

    cout << "how long will you be investing (in years)?\n";
    int years_to_invest{};
    if (!(cin >> years_to_invest)) {
        std::cerr << "not a valid amount of years\n";
        return 1;
    }

    cout << "cooking some calculations...\n";
    std::this_thread::sleep_for(1s);

    cout << "optimising instructions...\n";
    std::this_thread::sleep_for(1s);

    cout << "final touches...\n";
    std::this_thread::sleep_for(1s);

    cout << "==== Final Result ====\n";
    cout << getSimpleInterestResult(money_to_invest, annual_interest_rate, years_to_invest) << "\n";
}

str getSimpleInterestResult(const double principal_amount,
    const double annual_interest_rate, const int years_invested) {

    double final_result = principal_amount * (1 + annual_interest_rate * years_invested);
    return std::format("${:.2f}", final_result);
}