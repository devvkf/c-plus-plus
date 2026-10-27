#include <iostream>
#include <memory>
#include <format> // For std::format
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using str = std::string;
using std::vector;

using std::unique_ptr;
using std::make_unique;

template<class... Args>
void myprintln(std::format_string<Args...> fmt, Args&&... args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...) << "\n";
}


class Pokedex {
public:
    int nationalPokedexNumber{};
    str pokemonName{};
    str categoryClassification{};
    str type1{};
    unique_ptr<str> optionalType2{nullptr};
    double height{};
    double weight{};

    Pokedex() = default;

    Pokedex(int number, str name, str category, str t1, unique_ptr<str> t2, double h, double w)
        : nationalPokedexNumber(number),
          pokemonName(std::move(name)),
          categoryClassification(std::move(category)),
          type1(std::move(t1)),
          optionalType2(std::move(t2)),
          height(h),
          weight(w) {}

    // Movable
    Pokedex(Pokedex&&) noexcept = default;
    Pokedex& operator=(Pokedex&&) noexcept = default;

    // Non-copyable due to unique_ptr
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
};

int main() {
    vector<Pokedex> pokedex_db;

    while (true) {
        myprintln("\n==== welcome to the pokedex ====\n"
                "a. add new pokemon entry\n"
                "b. list elements in pokedex\n"
                "c. delete entry\n"
                "d. quit");

        char choice{};
        if (!(std::cin >> choice)) {
            break;
        }

        if (choice == 'a') {
            myprintln("Enter the National Pokedex Number:");
            int national_pokedex_number{};
            if (!(std::cin >> national_pokedex_number)) {
                std::cerr << "error: not an integer\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            myprintln("Enter the Pokemon name:");
            str pokemon_name{};
            std::getline(std::cin >> std::ws, pokemon_name);

            myprintln("Enter the category classification:");
            str category_classification{};
            std::getline(std::cin >> std::ws, category_classification);

            myprintln("Enter the type:");
            str type1{};
            std::getline(std::cin >> std::ws, type1);

            myprintln("Enter the second type\nIf not available, enter 0:");
            str input_type2{};
            std::getline(std::cin >> std::ws, input_type2);

            unique_ptr<str> type2{nullptr};
            if (input_type2 != "0") {
                type2 = make_unique<str>(input_type2);
            }

            myprintln("Enter height (in meters):");
            double height{};
            if (!(std::cin >> height)) {
                std::cerr << "error: not a valid number\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            myprintln("Enter weight (in kg):");
            double weight{};
            if (!(std::cin >> weight)) {
                std::cerr << "error: not a valid number\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            myprintln("Successfully added '{}' to the Pokedex!", pokemon_name);
            pokedex_db.emplace_back(national_pokedex_number,
                                    std::move(pokemon_name),
                                    std::move(category_classification),
                                    std::move(type1),
                                    std::move(type2),
                                    height,
                                    weight);
        } else if (choice == 'b') {
            if (pokedex_db.empty()) {
                myprintln("Pokedex is currently empty.");
            } else {
                myprintln("==== Pokedex Entries ({}) ====", pokedex_db.size());
                for (const auto& entry : pokedex_db) {
                    myprintln("#{:<4} Name: {}", entry.nationalPokedexNumber, entry.pokemonName);
                    myprintln("      Category: {}", entry.categoryClassification);
                    if (entry.optionalType2) {
                        myprintln("      Type: {} / {}", entry.type1, *entry.optionalType2);
                    } else {
                        myprintln("      Type: {}", entry.type1);
                    }
                    myprintln("      Height: {:.2f} m | Weight: {:.2f} kg", entry.height, entry.weight);
                }
            }
        } else if (choice == 'c') {
            if (pokedex_db.empty()) {
                myprintln("Pokedex is currently empty. Nothing to delete.");
                continue;
            }

            myprintln("Enter National Pokedex Number to delete:");
            int target_number{};
            if (!(std::cin >> target_number)) {
                std::cerr << "error: not an integer\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            auto it = std::find_if(pokedex_db.begin(), pokedex_db.end(), [target_number](const Pokedex& p) {
                return p.nationalPokedexNumber == target_number;
            });

            if (it != pokedex_db.end()) {
                myprintln("Deleted '{}' (#{:<4}) from Pokedex.", it->pokemonName, it->nationalPokedexNumber);
                pokedex_db.erase(it);
            } else {
                myprintln("Pokemon with number {} not found.", target_number);
            }
        } else if (choice == 'd') {
            myprintln("Exiting Pokedex. Goodbye!");
            break;
        } else {
            myprintln("Invalid option '{}'. Please select a, b, c, or d.", choice);
        }
    }

    return 0;
}
