#include <iostream>
#include <string>
#include <memory>

using str = std::string;
using std::cout;

class Student {
public:
    str name{};

    Student(str d) : name(std::move(d)) {
        cout << name << " spawned to RAM!\n";
    }

    ~Student() {
        std::cout << name << " destroyed!\n";
    }

    void study() const {
        std::cout << name << " is studying.\n";
    }
};

int main() {
    auto student1 = std::make_unique<Student>("Mark");
    student1->study();

    auto student2 = std::move(student1); // move
    if (!student1) {
        cout << "student1 is empty!\n";
    }

    student2->study();
    return 0;

    // ~Student() called
}