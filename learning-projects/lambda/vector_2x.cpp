#include <algorithm>
#include <vector>
#include <iostream>
#include <concepts>

using std::vector;
using std::cout;
using ch = char;

template <typename D>
concept canBeDouble = std::same_as<D, double>;

template <canBeDouble D>
static void check(D val) {
    cout << "passed\n";
}

template <typename D>
concept isChar = std::same_as<D, ch>;

int main() {
    vector<double> db;

    cout << "==== double vector ====\n"
            "a. add\n"
            "b. print vector\n"
            "c. clear vector\n"
            "choice:\n";
    ch input{};
    if (!(std::cin >> input)) {
        std::cerr << "invalid.\n";
        return 1;
    }

    switch (input) {
        case 'a': {
            double value{};
            if (!(std::cin >> value)) {
                std::cerr << "invalid number.\n";
                return 1;
            }
            db.push_back(value);
            break;
        }
        case 'b':
            for (const double value : db) {
                cout << value * 2 << '\n';
            }
            break;
        case 'c':
            db.clear();
            cout << "vector cleared\n";
            break;
        default:
            std::cerr << "invalid choice.\n";
            return 1;
    }

    return 0;
}