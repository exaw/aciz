
#include "helix.h"

#include <cmath>
#include <stdexcept>

#include "tolerance.h"

using namespace std;

namespace Aciz
{
    Helix::Helix (double r, double step)
    {
        if (CheckR (r) == false)
            throw logic_error ("Helix::Helix - need r > Tolerance::minRadius");

        r_ = r;
        step_ = step;
        stepByT_ = step / (2.0 * M_PI);
    }

    CurveType Helix::GetType () const
    {
        return CurveType::Helix;
    }

    Point Helix::GetPoint (double t) const
    {
        double x = r_ * cos (t);
        double y = r_ * sin (t);
        double z = stepByT_ * t;
        return {x, y, z};
    }

    Point Helix::GetDerivative (double t) const
    {
        double x = r_ * -sin (t);
        double y = r_ * cos (t);
        double z = stepByT_;
        return {x, y, z};
    }


    double Helix::GetR () const
    {
        return r_;
    }

    void Helix::SetR (double r)
    {
        if (CheckR (r) == false)
            throw logic_error ("Helix::SetR - need r > Tolerance::minRadius");

        r_ = r;
    }

    double Helix::GetStep () const
    {
        return step_;
    }

    void Helix::SetStep (double step)
    {
        step_ = step;
        stepByT_ = step / (2.0 * M_PI);
    }

    bool Helix::CheckR (double r) const
    {
        return r > Tolerance::minRadius;
    }
}