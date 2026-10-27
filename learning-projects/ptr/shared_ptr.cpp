#include <format> // For std::format
#include <iostream>
#include <memory>

template<class... Args>
void println(std::format_string<Args...> fmt, Args&&... args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...) << "\n";
}

struct Resource{
    Resource(){
        println("Resource Created");
    }

    ~Resource(){
        println("Resource Destroyed");
    }
};

int main(){
    std::shared_ptr<Resource> ptr = std::make_shared<Resource>();
    println("Use count: {}", ptr.use_count());
    {
        std::shared_ptr<Resource> ptr_2 = ptr;
        println("Count: {}", ptr.use_count());
    }
    println("Use count: {}", ptr.use_count());

    return 0;
}
