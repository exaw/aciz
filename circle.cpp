
#include "circle.h"

#include <cmath>
#include <stdexcept>

#include "tolerance.h"

using namespace std;

namespace Aciz
{

    Circle::Circle (double r)
    {
        if (CheckR (r) == false)
            throw logic_error ("Circle::Circle - need r > Tolerance::minRadius");

        r_ = r;
    }

    CurveType Circle::GetType () const
    {
        return CurveType::Circle;
    }

    Point Circle::GetPoint (double t) const
    {
        double x = r_ * cos (t);
        double y = r_ * sin (t);
        return {x, y, 0.0};
    }

    Point Circle::GetDerivative (double t) const
    {
        double x = r_ * -1 * sin (t);
        double y = r_ * cos (t);
        return {x, y, 0.0};
    }

    double Circle::GetR () const
    { return r_; }

    void Circle::SetR (double r)
    {
        if (CheckR (r) == false)
            throw logic_error ("Circle::SetR - r > Tolerance::minRadius");

        r_ = r;
    }

    bool Circle::CheckR (double r) const
    {
        return r > Tolerance::minRadius;
    };
}