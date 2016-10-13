#pragma once

#include <string>
#include <vector>
#include <memory>

namespace SortTest
{
    using Sortee_t = std::vector<int>;
    
    class Sorter
    {
    public:
        using UPtr_t = std::unique_ptr<Sorter>;
        
        virtual ~Sorter() = default;
        
        virtual auto Clone() const -> UPtr_t = 0;
        
        virtual auto Execute(Sortee_t&) const -> void = 0;
        virtual auto Name() const noexcept -> std::string = 0;
        virtual auto Description() const noexcept 
            -> std::string = 0;
    };
    
    using Sorters_t = std::vector<Sorter::UPtr_t>;
    
    class BubbleSorter final : public Sorter
    {
    public:
        auto Clone() const -> Sorter::UPtr_t override;
        auto Execute(Sortee_t&) const -> void override;
        auto Name() const noexcept -> std::string override;
        auto Description() const noexcept -> std::string override;
    };
    
    class OneByOneSorter final : public Sorter
    {
    public:
        auto Clone() const -> Sorter::UPtr_t override;
        auto Execute(Sortee_t&) const -> void override;
        auto Name() const noexcept -> std::string override;
        auto Description() const noexcept -> std::string override;
    };
    
    class MiddleSorter final : public Sorter
    {
        auto Clone() const -> Sorter::UPtr_t override;
        auto Execute(Sortee_t&) const -> void override;
        auto Name() const noexcept -> std::string override;
        auto Description() const noexcept -> std::string override;
    };
}
