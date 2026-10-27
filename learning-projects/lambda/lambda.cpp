#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<double> doubleDB = {15.2, 32.3, 98.9};

    std::sort(doubleDB.begin(), doubleDB.end()
        , [](const double d, const double e) {
            return d > e;
        });

    for (const auto& item : doubleDB) {
        std::cout << item << "\n";
    }
}