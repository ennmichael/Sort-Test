#include "rest.h"
#include <algorithm>
#include <chrono>

namespace SortTest
{
    auto Flow(Sortee_t& sortee, Factory& fct) noexcept -> void
    {
        Load(sortee);
        fct.PrintSet();
        Execute(sortee, fct);
    }
    
    auto Load(Sortee_t& sortee) noexcept -> void
    {
        auto newSize = int { };
        std::cin >> newSize;
        sortee.resize(newSize);
        
        // Sub-optimal, should use std::copy
        std::for_each(sortee.begin(), sortee.end(),
            [](auto& elem) noexcept
            {
                std::cin >> elem;
            }
        );
        
        std::cout << std::endl;
    }
    
    auto Execute(Sortee_t& sortee, Factory& fct) -> void
    {
        auto copy = Sortee_t { };
        
        for (const auto& sorter : fct.GetSorters())
        {
            copy = sortee;
            
            auto now = []
            {
                auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now().time_since_epoch());
                return ms.count();
            };
            
            auto start = now();
            
            std::cout << ' ' << sorter->Name() << ':' << std::endl;
            std::cout << sorter->Description() << "\n\n";
            
            sorter->Execute(copy);
            
            std::cout << "  Vreme potrebno: "
            << (now() - start) << " milisekundi.\n\n";
            
            std::cout << "Rezultat: " << copy << "\n\n";
        }
    }
}
