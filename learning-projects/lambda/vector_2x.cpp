#include <algorithm>
#include <vector>
#include <iostream>
#include <concepts>

using std::vector;
using std::cout;
auto& transform_r = std::ranges::transform;

int main() {
    vector<double> db = {15.3, 76.4, 245.9, 956.2};

    transform_r(db, db.begin(),
                           [](const double d) {
                               return 2 * d;
                           });

    for (const double val : db) {
        cout << val << '\n';
    }

    return 0;
}