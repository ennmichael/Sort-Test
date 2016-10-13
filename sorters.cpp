#include "sorters.h"
#include <algorithm>

#include <iostream> // test

namespace SortTest
{
    auto BubbleSorter::Clone() const -> Sorter::UPtr_t
    {
        return std::make_unique<BubbleSorter>(*this);
    }
    
    auto BubbleSorter::Execute(Sortee_t& sortee) const -> void
    {
        auto doneWork = bool { };
        
        do
        {
            doneWork = false;
            
            for (auto i = sortee.begin() + 1; i != sortee.end(); ++i )
            {
                auto& current = *i;
                auto& previous = *(i - 1);
                
                if (previous > current)
                {
                    std::swap(current, previous);
                    doneWork = true;
                }
            }
        }
        while(doneWork);
    }
    
    auto BubbleSorter::Name() const noexcept -> std::string
    {
        return "Bubble Sort";
    }
    
    auto BubbleSorter::Description() const noexcept -> std::string
    {
        return "Prolazi kroz niz i obrce svaki par { i, i - 1 } "
               "ukoliko nisu sortirani po redu. "
               "Rezultat ovoga je pomeranje najvecih vrednosti "
               "desno, a samim tim najmanjih vrednoisti levo";
    }
    
    auto OneByOneSorter::Clone() const -> Sorter::UPtr_t
    {
        return std::make_unique<OneByOneSorter>(*this);
    }
    
    auto OneByOneSorter::Execute(Sortee_t& sortee) const -> void
    {
        for (auto i = sortee.begin(); i!= sortee.end(); ++i)
        {
            auto min = int { };
            
            std::for_each(i + 1, sortee.end(),
                [&i, &min](auto& j) noexcept
                {
                    if (j < min)
                        std::swap(*i, j);
                }
            );
        }
    }
    
    auto OneByOneSorter::Name() const noexcept -> std::string
    {
        return "Jedan po jedan";
    }
    
    auto OneByOneSorter::Description() const noexcept 
        -> std::string
    {
        return "Sortira niz sa leve strane ka desnoj. "
               "Pronalazi najmanji element u nizu i "
               "zamenjuje taj i najleviji nesortirani element. "
               "Ovo se ponavlja dok niz nije skroz sortiran.";
    }
    
    auto MiddleSorter::Clone() const -> Sorter::UPtr_t
    {
        return std::make_unique<MiddleSorter>(*this);
    }
    
    auto MiddleSorter::Execute(Sortee_t& sortee) const 
        -> void
    {
        auto size = sortee.size();
        auto startIter = sortee.begin();
        
        for (auto sortedCount = std::size_t { };
             sortedCount < size;
             ++sortedCount
        )
        {
            auto middleIter 
                = startIter + std::distance(
                    startIter, sortee.end()) / 2;
            std::swap(*startIter, *middleIter);
            
            for (const auto& elem : sortee)
                std::cout << elem << ' ';
            std::cout << std::endl;
            
            ++startIter;
        }
    }
    
    auto MiddleSorter::Name() const noexcept -> std::string
    {
        return "Sortiranje iz sredine";
    }
    
    auto MiddleSorter::Description() const noexcept -> std::string
    {
        return "";
    }
}
