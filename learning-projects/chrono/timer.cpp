#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using ch = char;

int main() {
    using namespace std::chrono_literals;

    cout << "==== timer by lambda ====\n"
            "enter 'a' to start:\n";
    ch input{};
    std::cin >> input;

    input = static_cast<ch>(std::tolower(input));
    if (input == 'a') {
        cout << "how many seconds to "
                "count down to?\n";
        if (int sec{}; !(std::cin >> sec)) {
            std::cerr << "invalid input\n";
            return 1;
        }
        else {
            while (sec >= 0) {
                std::this_thread::sleep_for
                (1s);
                cout << "sec: " << sec << '\n';
                --sec;
            }
            cout << "done\n";
        }
    }
    else {
        std::cerr << "invalid input\n";
        return 1;
    }
    return 0;
}