#include <iostream>
#include <string>

int main() {
    std::string name = "Mark";
    std::string *name_pointer = &name;

    std::cout << "Original value: " << name << '\n';
    std::cout << "Address of pointer: " << name_pointer << '\n';
    std::cout << "Pointer value: " << *name_pointer << '\n';

    return 0;
}