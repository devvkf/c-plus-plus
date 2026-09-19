#include <cctype>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

namespace weight_conversion
{
    constexpr double kg_to_lb_converter = 2.2046226218;
    constexpr double lb_to_kg_converter = 0.45359237;
}

namespace length_conversion
{
    constexpr double universal_inch_cm_converter = 2.54;
}

static char toLower(char choice);
static double getWeightConversionResult(char choice, double weight_input);
static double getLengthConversionResult(char choice, double length_input);

int main()
{
    cout << "==== welcome! ====\n"
            "choices:\n"
            "a. convert weight (kg/lb)\n"
            "b. convert length (cm/inch)\n"
            "choice: ";

    char mainChoiceOption{};
    if (!(cin >> mainChoiceOption))
    {
        std::cerr << "Could not read your choice.\n";
        return 1;
    }

    mainChoiceOption = toLower(mainChoiceOption);

    cout << std::fixed << std::setprecision(2);

    if (mainChoiceOption == 'a')
    {
        cout << "convert from:\n"
                "a. kg to lb\n"
                "b. lb to kg\n"
                "choice: ";

        char weightChoiceOption{};
        if (!(cin >> weightChoiceOption))
        {
            std::cerr << "Could not read your choice.\n";
            return 1;
        }

        weightChoiceOption = toLower(weightChoiceOption);

        if (weightChoiceOption != 'a' && weightChoiceOption != 'b')
        {
            std::cerr << "Not a valid weight-conversion choice.\n";
            return 1;
        }

        double unitToConvert{};

        if (weightChoiceOption == 'a')
        {
            cout << "input kg: ";
        }
        else
        {
            cout << "input lb: ";
        }

        if (!(cin >> unitToConvert))
        {
            std::cerr << "Not a valid measurement.\n";
            return 1;
        }

        const double result =
            getWeightConversionResult(weightChoiceOption, unitToConvert);

        if (weightChoiceOption == 'a')
        {
            cout << unitToConvert << " kg = " << result << " lb\n";
        }
        else
        {
            cout << unitToConvert << " lb = " << result << " kg\n";
        }
    }
    else if (mainChoiceOption == 'b')
    {
        cout << "convert from:\n"
                "a. cm to inch\n"
                "b. inch to cm\n"
                "choice: ";

        char lengthChoiceOption{};
        if (!(cin >> lengthChoiceOption))
        {
            std::cerr << "Could not read your choice.\n";
            return 1;
        }

        lengthChoiceOption = toLower(lengthChoiceOption);

        if (lengthChoiceOption != 'a' && lengthChoiceOption != 'b')
        {
            std::cerr << "Not a valid length-conversion choice.\n";
            return 1;
        }

        double unitToConvert{};

        if (lengthChoiceOption == 'a')
        {
            cout << "input cm: ";
        }
        else
        {
            cout << "input inch: ";
        }

        if (!(cin >> unitToConvert))
        {
            std::cerr << "Not a valid measurement.\n";
            return 1;
        }

        const double result =
            getLengthConversionResult(lengthChoiceOption, unitToConvert);

        if (lengthChoiceOption == 'a')
        {
            cout << unitToConvert << " cm = " << result << " inch\n";
        }
        else
        {
            cout << unitToConvert << " inch = " << result << " cm\n";
        }
    }
    else
    {
        std::cerr << "Not a valid menu choice.\n";
        return 1;
    }

    return 0;
}

static char toLower(char choice)
{
    return static_cast<char>(
        std::tolower(static_cast<unsigned char>(choice)));
}

static double getWeightConversionResult(char choice, double weight_input)
{
    if (choice == 'a')
    {
        return weight_input * weight_conversion::kg_to_lb_converter;
    }

    return weight_input * weight_conversion::lb_to_kg_converter;
}

static double getLengthConversionResult(char choice, double length_input)
{
    if (choice == 'a')
    {
        return length_input / length_conversion::universal_inch_cm_converter;
    }

    return length_input * length_conversion::universal_inch_cm_converter;
}