#include <iostream>
#include <unordered_map>
#include <string>

int main(){
    std::unordered_map<std::string, int> girls;
    girls["cindy"] = 13;
    girls["devlyn"] = 14;

    std::cout << girls["cindy"] << '\n';
    return 0;
}
