
#include "point.h"

#include <iostream>

namespace Aciz
{
    std::ostream &operator<< (std::ostream &out, const Point &p)
    {
        out << "( " << p.x << ", " << p.y << ", " << p.z << ")";
        return out;
    }
}