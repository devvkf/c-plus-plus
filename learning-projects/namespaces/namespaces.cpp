#include <iostream>
using std::cout;

namespace different_value {
    static int value = 2;
}

namespace other_value {
    static int value = 6;
}

int main() {
    using namespace different_value;
    int value = 9;

    cout << value << '\n'; // 2
    cout << other_value::value << '\n'; // 6
}