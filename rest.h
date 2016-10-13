#pragma once

#include "sorters.h"
#include "factory.h"
#include <iostream>

namespace SortTest
{
    auto Flow(Sortee_t&, Factory&) noexcept -> void;
    auto Load(Sortee_t&) noexcept -> void;
    auto Execute(Sortee_t&, Factory&) -> void;
}
