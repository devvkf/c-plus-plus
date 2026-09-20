#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::transform;

int main() {
    vector<double> db = {15.3, 76.4, 245.9, 956.2};

    std::ranges::transform(db, db.begin(),
                           [](const double d) {
                               return 2 * d;
                           });

    for (const double val : db) {
        cout << val << '\n';
    }

    return 0;
}