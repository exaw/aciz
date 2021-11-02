
#include <algorithm>
#include <cassert>
#include <exception>
#include <iostream>
#include <memory>
#include <random>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace std;
using namespace Aciz;

class CurveGenerator
{
public:
    CurveGenerator (double minRadius, double maxRadius, double minHelixStep, double maxHelixStep)
    {
        radiusDist_ = uniform_real_distribution<> (minRadius, maxRadius);
        helixStepDist_ = uniform_real_distribution<> (minHelixStep, maxHelixStep);
        geomTypeDist_ = uniform_int_distribution<> (0, 2);
    }

    shared_ptr<Curve> Generate ()
    {
        int geomType = geomTypeDist_ (mtGen_);
        assert (geomType == 0 || geomType == 1 || geomType == 2);

        if (geomType == 0)
            return GenerateCircle ();
        else if (geomType == 1)
            return GenerateEllipse ();
        else if (geomType == 2)
            return GenerateHelix ();

        return nullptr;
    }

    shared_ptr<Ellipse> GenerateEllipse ()
    {
        double r1 = radiusDist_ (mtGen_);
        double r2 = radiusDist_ (mtGen_);
        auto ellipse = make_shared<Ellipse> (r1, r2);
        return ellipse;
    }

    shared_ptr<Circle> GenerateCircle ()
    {
        double r = radiusDist_ (mtGen_);
        auto circle = make_shared<Circle> (r);
        return circle;
    }

    shared_ptr<Helix> GenerateHelix ()
    {
        double r = radiusDist_ (mtGen_);
        double step = helixStepDist_ (mtGen_);
        auto helix = make_shared<Helix> (r, step);

        return helix;
    }

private:

    std::mt19937 mtGen_;
    uniform_real_distribution<> radiusDist_;
    uniform_real_distribution<> helixStepDist_;
    uniform_int_distribution<> geomTypeDist_;

};

double GetRadiiSumParallel (const vector<shared_ptr<Circle>>& circles);

int main (int argc, char *argv[])
{
    int nbCurve = 50;

    CurveGenerator curveGenerator (1, 30, 5, 10);
    vector<shared_ptr<Curve>> curves (nbCurve);

    try
    {
        for (int i = 0; i < nbCurve; i++)
        {
            curves[i] = curveGenerator.Generate ();
        }

        cout<<"Generated curves:\n";
        for (int i = 0; i < nbCurve; i++)
        {
            const auto& curve = curves[i];
            auto type = curve->GetType ();
            cout << i+1 << ". " << (type == CurveType::Circle ? "Circle" :
                    type == CurveType::Ellipse ? "Ellipse" :
                    type == CurveType::Helix ? "Helix" : "Other")  << "\n";
        }
        cout<<"===============================================================\n";

        cout<<"PI/4:\n";
        for (int i = 0; i < nbCurve; i++)
        {
            const auto& curve = curves[i];
            auto p = curve->GetPoint (M_PI_4);
            auto d = curve->GetDerivative(M_PI_4);
            cout << i+1 << ". " << "P: " << p <<", D1: " << d << "\n";
        }
        cout<<"===============================================================\n";

        size_t nbCircle = count_if ( begin(curves), end(curves),
                                     [] (const auto& curve) { return curve->GetType() == CurveType::Circle; } );

        vector<shared_ptr<Circle>> circles;
        circles.reserve (nbCircle);
        for (const auto &curve : curves)
        {
            if ( curve->GetType() == CurveType::Circle )
                circles.push_back (dynamic_pointer_cast<Circle> (curve));
        }

        cout<<"Circles:\n";
        for (int i = 0; i < nbCircle; i++)
        {
            const auto& circle = circles[i];
            cout << i+1 << ". "<< "R: " << circle->GetR()<< "\n";
        }
        cout<<"===============================================================\n";

        sort ( begin(circles), end(circles),
                   [] (const auto& a, const auto& b ) { return a->GetR() < b->GetR(); } );

        cout<<"Sorted Circles:\n";
        for (int i = 0; i < nbCircle; i++)
        {
            const auto& circle = circles[i];
            cout << i+1 << ". " << "R: " << circle->GetR()<< "\n";
        }
        cout<<"===============================================================\n";

        cout<<"Sum circles radii:\n";
        double sum = 0.0;
        for ( auto c : circles)
            sum += c->GetR();
        cout<<"Sum: "<<sum<<"\n";
        cout<<"===============================================================\n";

        cout<<"Parallel Sum circles radii:\n";
        double psum = GetRadiiSumParallel ( circles );

        cout<<"Parallel Sum: "<<psum<<"\n";
        cout<<"===============================================================\n";
    }
    catch (std::exception &e)
    {
        cerr << "Std exception: " << e.what () << endl;
    }
}