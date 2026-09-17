#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main() {
    vector<int> nums = {5, 2, 8, 1, 9};

    std::ranges::sort(nums, []
              (const int d, const int e) {
                          return d < e;
                      });

    for (const auto& value : nums) {
        std::cout << value << std::endl;
    }
}