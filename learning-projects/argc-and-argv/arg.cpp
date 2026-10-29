#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::cout << "Total arguments passed: " << argc << "\n\n";

    for (int d = 0; d < argc; d++){
        std::cout << "argv[" << d << "] = " << argv[d] << '\n';
    }
}
