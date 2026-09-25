#include <print>
#include <iostream>
#include <memory>

struct Resource{
    Resource(){
        std::println("Resource Created");
    }

    ~Resource(){
        std::println("Resource Destroyed");
    }
};

int main(){
    std::shared_ptr<Resource> ptr = std::make_shared<Resource>();
    std::println("Use count: {}", ptr.use_count());
    {
        std::shared_ptr<Resource> ptr_2 = ptr;
        std::println("Count: {}", ptr.use_count());
    }
    std::println("Use count: {}", ptr.use_count());
    
    return 0;
}