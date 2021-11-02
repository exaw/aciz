
#include "ellipse.h"
#include "tolerance.h"

#include <cmath>
#include <stdexcept>

using namespace std;

namespace Aciz
{

    Ellipse::Ellipse (double r1, double r2)
    {
        if (CheckR (r1, r2) == false)
            throw logic_error ("Ellipse::Ellipse - need r1 > Tolerance::minRadius && r2 > Tolerance::minRadius");

        r1_ = r1;
        r2_ = r2;
    }

    CurveType Ellipse::GetType () const
    {
        return CurveType::Ellipse;
    }

    Point Ellipse::GetPoint (double t) const
    {
        double x = r1_ * cos (t);
        double y = r2_ * sin (t);
        return {x, y, 0.0};
    }

    Point Ellipse::GetDerivative (double t) const
    {
        double x = r1_ * -sin (t);
        double y = r2_ * cos (t);
        return {x, y, 0.0};
    }

    std::pair<double, double> Ellipse::GetR () const
    {
        return {r1_, r2_};
    }

    void Ellipse::SetR (double r1, double r2)
    {
        if (CheckR (r1, r2) == false)
            throw logic_error ("Circle::SetR - need r1 > Tolerance::minRadius && r2 > Tolerance::minRadius");

        r1_ = r1;
        r2_ = r2;
    }

    bool Ellipse::CheckR (double r1, double r2) const
    {
        return r1 > Tolerance::minRadius && r2 > Tolerance::minRadius;
    }
}