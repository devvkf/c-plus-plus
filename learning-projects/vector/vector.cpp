#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main() {
    vector<double> decimalDatabase;

    decimalDatabase.push_back(1.1);
    decimalDatabase.push_back(2.2);
    decimalDatabase.push_back(3.0);

    for (const double fp : decimalDatabase) {
        cout << fp << '\n';
    }

    return 0;
}