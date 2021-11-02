#pragma once

#include "point.h"

namespace Aciz
{
    enum class CurveType
    {
        Circle, Ellipse, Helix, Other
    };

    class Curve
    {
    public:

        virtual CurveType GetType () const = 0;

        virtual Point GetPoint (double t) const = 0;

        virtual Point GetDerivative (double t) const = 0;

        virtual ~Curve () = default;
    };
}
