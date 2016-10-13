#pragma once

#include "sorters.h"
#include <array>

namespace SortTest
{
    struct SorterFlag final
    {
        explicit SorterFlag(Sorter::UPtr_t) noexcept;
        
        Sorter::UPtr_t value { nullptr };
        bool flag { true };
    };
    
    class Factory final
    {
    public:
        using Flags_t = std::array<SorterFlag, 3>;
        // Size will change
        
        auto PrintSet() const noexcept -> void;
        auto ToggleFlag(int) noexcept -> void;
        auto GetSorters() const -> Sorters_t;
        
    private:
        Flags_t m_flags
        {
            SorterFlag { std::make_unique<BubbleSorter>() },
            SorterFlag { std::make_unique<OneByOneSorter>() },
            SorterFlag { std::make_unique<MiddleSorter>() }
        };
    };
    
    auto operator<<(std::ostream&, const Factory::Flags_t&)
        noexcept -> std::ostream&;
    auto operator<<(std::ostream&, const Sortee_t&) 
        noexcept -> std::ostream&;
}
