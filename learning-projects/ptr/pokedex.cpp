#include <iostream>
#include <memory>
#include <print> // Native C++ standard header [1]
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using str = std::string;
using std::vector;
using std::println; // Pure, native std::println definition [1]
using std::unique_ptr;
using std::make_unique;


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
        println("\n==== welcome to the pokedex ====\n"
                "a. add new pokemon entry\n"
                "b. list elements in pokedex\n"
                "c. delete entry\n"
                "d. quit");

        char choice{};
        if (!(std::cin >> choice)) {
            break;
        }

        if (choice == 'a') {
            println("Enter the National Pokedex Number:");
            int national_pokedex_number{};
            if (!(std::cin >> national_pokedex_number)) {
                std::cerr << "error: not an integer\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            println("Enter the Pokemon name:");
            str pokemon_name{};
            std::getline(std::cin >> std::ws, pokemon_name);

            println("Enter the category classification:");
            str category_classification{};
            std::getline(std::cin >> std::ws, category_classification);

            println("Enter the type:");
            str type1{};
            std::getline(std::cin >> std::ws, type1);

            println("Enter the second type\n"
                    "If not available, enter 0:");
            str input_type2{};
            std::getline(std::cin >> std::ws, input_type2);

            unique_ptr<str> type2{nullptr};
            if (input_type2 != "0") {
                type2 = make_unique<str>(input_type2);
            }

            println("Enter height (in meters):");
            double height{};
            if (!(std::cin >> height)) {
                std::cerr << "error: not a valid number\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            println("Enter weight (in kg):");
            double weight{};
            if (!(std::cin >> weight)) {
                std::cerr << "error: not a valid number\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            println("Successfully added '{}' to the Pokedex!", pokemon_name);
            pokedex_db.emplace_back(national_pokedex_number,
                                    std::move(pokemon_name),
                                    std::move(category_classification),
                                    std::move(type1),
                                    std::move(type2),
                                    height,
                                    weight);
        } else if (choice == 'b') {
            if (pokedex_db.empty()) {
                println("Pokedex is currently empty.");
            } else {
                println("==== Pokedex Entries ({}) ====", pokedex_db.size());
                for (const auto& entry : pokedex_db) {
                    println("#{:<4} Name: {}", entry.nationalPokedexNumber, entry.pokemonName);
                    println("      Category: {}", entry.categoryClassification);
                    if (entry.optionalType2) {
                        println("      Type: {} / {}", entry.type1, *entry.optionalType2);
                    } else {
                        println("      Type: {}", entry.type1);
                    }
                    println("      Height: {:.2f} m | Weight: {:.2f} kg", entry.height, entry.weight);
                }
            }
        } else if (choice == 'c') {
            if (pokedex_db.empty()) {
                println("Pokedex is currently empty. Nothing to delete.");
                continue;
            }

            println("Enter National Pokedex Number to delete:");
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
                println("Deleted '{}' (#{:<4}) from Pokedex.", it->pokemonName, it->nationalPokedexNumber);
                pokedex_db.erase(it);
            } else {
                println("Pokemon with number {} not found.", target_number);
            }
        } else if (choice == 'd') {
            println("Exiting Pokedex. Goodbye!");
            break;
        } else {
            println("Invalid option '{}'. Please select a, b, c, or d.", choice);
        }
    }

    return 0;
}