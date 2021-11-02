
#pragma once

#include <iosfwd>
namespace Aciz
{
    struct Point
    {
        double x = 0.0, y = 0.0, z = 0.0;
    };

    std::ostream &operator<< (std::ostream &out, const Point &p);
}

