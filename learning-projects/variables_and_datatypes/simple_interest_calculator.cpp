// A = P(1 + rt)

#include <iostream>
#include <format>
#include <chrono>
#include <string>
#include <thread>

using str = std::string;
using std::cout, std::cin, std::flush;

static str getSimpleInterestResult(double principal_amount,
                                   double annual_interest_rate, int years_invested);

int main() {
    using namespace std::chrono_literals;

    cout << "==== simple interest calculator ====\n"
            "1. how much money will you invest? (in $)\n";
    double money_to_invest{};
    if (!(cin >> money_to_invest)) {
        std::cerr << "not a valid integer\n";
        return 1;
    }

    cout << "2. what's the annual interest rate (in %)?\n";
    double annual_interest_rate{};
    if (!(cin >> annual_interest_rate)) {
        std::cerr << "not a valid interest rate\n";
        return 1;
    }
    annual_interest_rate = annual_interest_rate / 100;

    cout << "3. how long will you be investing (in years)?\n";
    int years_to_invest{};
    if (!(cin >> years_to_invest)) {
        std::cerr << "not a valid amount of years\n";
        return 1;
    }

    cout << "\n[ parsing variables into financial engine... ]\n" << flush;
    std::this_thread::sleep_for(400ms); // Quick check

    cout << "[ simulating historical standard yields...   ]\n" << flush;
    std::this_thread::sleep_for(900ms); // Longest pause: simulates intense work

    cout << "[ compiling instruction matrix...           ]\n" << flush;
    std::this_thread::sleep_for(300ms); // Snappy finish

    cout << "\n==== Final Result ====\n";
    cout << getSimpleInterestResult(money_to_invest, annual_interest_rate, years_to_invest) << "\n";
}

static str getSimpleInterestResult(const double principal_amount,
    const double annual_interest_rate, const int years_invested) {

    double final_result = principal_amount * (1 + annual_interest_rate * years_invested);
    return std::format("${:.2f}", final_result);
}
