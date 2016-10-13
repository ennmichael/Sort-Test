#include "sorters.h"
#include "rest.h"
#include <iostream>
#include <chrono>

int main() 
{
    using namespace SortTest;
    
    auto fct = Factory { };
    auto sortee = Sortee_t { };
    auto dummy = std::string { };
    
    Flow(sortee, fct);
    
    using namespace std::chrono;
    auto ms = duration_cast< milliseconds >(
        system_clock::now().time_since_epoch());
    std::cout << ms.count();
    
    return 0;
}
