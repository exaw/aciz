#pragma once

#include "curve.h"
#include "point.h"
#include <utility>

namespace Aciz
{
    class Ellipse : public Curve
    {
    public:

        Ellipse () = default;

        Ellipse (double r1, double r2);

        CurveType GetType () const override;

        Point GetPoint (double t) const override;

        Point GetDerivative (double t) const override;

        std::pair<double, double> GetR () const;

        void SetR (double r1, double r2);

    private:

        bool CheckR (double r1, double r2) const;

        double r1_ = 1.0;
        double r2_ = 1.0;
    };
}
