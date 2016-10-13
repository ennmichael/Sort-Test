#include "factory.h"
#include "sorters.h"
#include <iostream>

namespace SortTest
{
    SorterFlag::SorterFlag(Sorter::UPtr_t newValue) noexcept
        : value { std::move(newValue) }
    {
    }
    
    auto Factory::PrintSet() const noexcept  -> void
    {
        std::cout << m_flags << std::endl;
    }
    
    auto Factory::ToggleFlag(int index) noexcept -> void
    {
        if (index < 0 or index > m_flags.size())
        {
            std::cout << "Invalid index\n";
            return;
        }
        
        m_flags[index].flag = !m_flags[index].flag;
    }
    
    auto Factory::GetSorters() const -> Sorters_t
    {
        auto result = Sorters_t { };
        
        for (const auto& elem : m_flags)
            result.emplace_back(elem.value->Clone());
        
        return result;
    }
    
    auto operator<<(std::ostream& os,
                    const Factory::Flags_t& flags) 
    noexcept -> std::ostream&
    {
        auto counter = int { };
        
        for (const auto& elem : flags)
        {
            if (!elem.value)
            {
                std::cout << "Serious error in code!!!\n";
                continue; // Should never happen
            }
            
            os << counter << ' '
            << elem.value->Name() << ' ' 
            << elem.flag << '\n';
            
            ++ counter;
        }
        
        return os;
    }
    
    auto operator<<(std::ostream& os, const Sortee_t& sortee) 
        noexcept -> std::ostream&
    {
        for (const auto& elem : sortee)
            os << elem << ' ';
        return os;
    }
}
