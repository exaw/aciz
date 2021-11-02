#pragma once

#include "curve.h"
#include "point.h"

namespace Aciz
{

    class Circle : public Curve
    {
    public:

        Circle () = default;

        Circle (double r);

        CurveType GetType () const override;

        Point GetPoint (double t) const override;

        Point GetDerivative (double t) const override;

        double GetR () const;

        void SetR (double r);

    private:

        bool CheckR (double r) const;

        double r_ = 1.0;
    };

}
