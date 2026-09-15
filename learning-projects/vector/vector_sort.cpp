#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;

static char toLower(const char& choice);

int main() {
    vector<double> doubleDB;
    char userChoice{};
    while (userChoice != 'e') {
        cout << "---- database sort ----\n"
                "a. add new element (double)\n"
                "b. sort ascending\n"
                "c. sort descending\n"
                "d. view db\n"
                "e. quit\n"
                "choice:\n";
        cin >> userChoice;

        userChoice = toLower(userChoice);

        switch (userChoice) {
            case 'a': {
                cout << "what double to add?\n";
                double doubleToAdd{};
                if (!(cin >> doubleToAdd)) {
                    std::cerr << "not a valid double, try again.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                doubleDB.push_back(doubleToAdd);
                break;
            }

            case 'b': {
                std::sort(doubleDB.begin(), doubleDB.end());
                cout << "sort by ascending done\n";
                break;
            }
            case 'c': {
                std::sort(doubleDB.begin(), doubleDB.end(), std::greater<double>());
                cout << "sort by descending done\n";
                break;
            }
            case 'd': {
                for (const double dbItems : doubleDB) {
                    cout << dbItems << "\n";
                }
                break;
            }
            case 'e': {
                cout << "bye!\n";
                break;
            }
            default:
                std::cerr << "an error occurred, please try again.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
        }
    }
}

static char toLower(const char& choice) {
    return static_cast<char>
    (std::tolower(static_cast<unsigned char>
        (choice)));
}
