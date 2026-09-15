#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main() {
    vector<double> decimalDatabase;

    decimalDatabase.push_back(1.0);
    decimalDatabase.push_back(2.0);
    decimalDatabase.push_back(3.0);

    for (int fp : decimalDatabase) {
        cout << fp << '\n';
    }

    return 0;
}