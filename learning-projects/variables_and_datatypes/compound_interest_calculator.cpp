// A = P(1 + r/n)^nt + PMT * [((1 + r/n)^nt - 1) / (r/12)]

#include <iostream>
#include <cmath>
#include <string>
#include <format>

using std::cout;
using str = std::string;

// FIX 1: Updated signature to pass the monthly contribution (PMT)
static str getResult(double principal_amount, double monthly_contribution, double annual_interest_rate_format,
                     int compound_per_year, double time_invested);

int main() {
    double principal_amount{};
    double extra_money_per_month_invest{0.0}; // Default to 0 if 'n'
    double annual_interest_rate_raw{};
    double annual_interest_rate_format{};
    int compound_per_year{};
    double time_invested{};

    cout << "==== compound interest calculator ====\n"
            "how much money ($) have you invested?\n";
    if (!(std::cin >> principal_amount)) {
        std::cerr << "invalid input, not a number.\n";
        return 1;
    }

    cout << "what is the annual interest rate (in %)?\n";
    if (!(std::cin >> annual_interest_rate_raw) || annual_interest_rate_raw < 1) {
        std::cerr << "invalid input, not a valid interest rate.\n";
        return 1;
    }
    annual_interest_rate_format = annual_interest_rate_raw / 100;

    cout << "how many times do you compound per year?\n";
    if (!(std::cin >> compound_per_year)) {
        std::cerr << "invalid input, not a number.\n";
        return 1;
    }

    cout << "how long are you investing this money? (in years)\n";
    if (!(std::cin >> time_invested)) {
        std::cerr << "invalid input, not a number.\n";
        return 1;
    }

    cout << "will you be adding extra money to invest every month? (y/n)\n ";
    str extra_money_config_question{};
    std::getline(std::cin >> std::ws, extra_money_config_question);

    if (extra_money_config_question == "y") {
        cout << "how much will you be investing extra every month? (in $)\n";
        if (!(std::cin >> extra_money_per_month_invest)) {
            std::cerr << "invalid input, not a number.\n";
            return 1;
        }
        // FIX 2: Removed the upfront calculation. We pass it clean to the formula now.
    }
    else if(extra_money_config_question != "n") {
        std::cerr << "invalid input, not a valid choice.\n";
        return 1;
    }

    cout << "==== Final amount: ====\n";
    // FIX 3: Pass the monthly contribution into our updated math function
    cout << getResult(principal_amount, extra_money_per_month_invest, annual_interest_rate_format, compound_per_year, time_invested) << "\n";
}

static str getResult(const double principal_amount, const double monthly_contribution, const double annual_interest_rate_format,
                     const int compound_per_year, const double time_invested) {

    // 1. Calculate the standard lump-sum compound interest factor
    double compound_factor = std::pow((1 + (annual_interest_rate_format / compound_per_year)), compound_per_year * time_invested);
    double principal_future_value = principal_amount * compound_factor;

    // 2. Calculate the future value of the recurring monthly contributions
    // We adjust the annual rate to a monthly rate denominator (r / 12)
    double monthly_rate = annual_interest_rate_format / 12.0;
    double contributions_future_value = 0.0;

    if (monthly_contribution > 0.0) {
        contributions_future_value = monthly_contribution * ((compound_factor - 1.0) / monthly_rate);
    }

    // Total final balance
    double total_result = principal_future_value + contributions_future_value;

    return std::format("${:.2f}", total_result);
}
