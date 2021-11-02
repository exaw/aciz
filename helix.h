#pragma once

#include <cmath>

#include "curve.h"
#include "point.h"

namespace Aciz
{

    class Helix : public Curve
    {
    public:

        Helix () = default;

        Helix (double r, double step);

        CurveType GetType () const override;

        Point GetPoint (double t) const override;

        Point GetDerivative (double t) const override;

        double GetR () const;

        void SetR (double r);

        double GetStep () const;

        void SetStep (double step);

    private:

        bool CheckR (double r) const;

        double r_ = 1.0;
        double step_ = 1.0;
        double stepByT_ = 1.0 / (2.0 * M_PI);
    };

}