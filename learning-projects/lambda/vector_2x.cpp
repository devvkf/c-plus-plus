#include <algorithm>
#include <vector>
#include <iostream>
#include <concepts>

using std::vector;
using std::cout;
auto& transform_r = std::ranges::transform;
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
    vector<double> db = {};
    transform_r(db, db.begin(),
                           [](const double d) {
                               return 2 * d;
                           });

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

    cout << input;

    return 0;
}