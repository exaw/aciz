
#include <array>
#include <cassert>
#include <cmath>
#include <vector>

#include "simple_svg_1.0.0.hpp"

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace std;

class SvgWriter
{

public:

    SvgWriter (const string &svgFile, double width, double height)
    {
        using namespace svg;
        Dimensions dimensions (width, height);
        doc_ = Document (svgFile, Layout (dimensions, Layout::BottomLeft, 1, Point (50, 50)));

        Polygon border (Stroke (3, Color::Green));
        border << Point (-width / 2, -height / 2) << Point (width / 2, -height / 2)
               << Point (width / 2, height / 2) << Point (-width / 2, height / 2);
        doc_ << border;
    }

    void SetPoints (const vector<Aciz::Point> &points)
    {
        using namespace svg;
        array<Color, 3> colors = { Color::Red, Color::Blue, Color::Green};

        for (int i = 0; i < points.size (); i++)
        {
            Aciz::Point p = points[i];
            Point t (p.x, p.y);
            Circle circle (t, 1, Fill (Color::Black), Stroke (0.2, colors[i%3]));
            doc_ << circle;
        }
    }

    void SetDerivatives (const vector<Aciz::Point> &basePoints,
                         const vector<Aciz::Point> &derivs)
    {
        using namespace svg;
        assert (basePoints.size () == derivs.size ());

        array<Color, 3> colors = { Color::Red, Color::Blue, Color::Green};
        for (int i = 0; i < derivs.size (); i++)
        {
            Aciz::Point p1 = basePoints[i];
            Aciz::Point d = derivs[i];
            Aciz::Point p2 { p1.x + d.x, p1.y + d.y, p1.z + d.z };

            Line line ( Point (p1.x, p1.y), Point (p2.x, p2.y), Stroke (0.25, colors[i%3]) );
            doc_ << line;
        }
    }

    ~SvgWriter ()
    {
        doc_.save ();
    }

private:
    svg::Document doc_;
};

void PrintCircle ()
{
    Aciz::Circle circle (20);
    vector<Aciz::Point> points;
    vector<Aciz::Point> derivs;

    for (int i = 0; i <= 360; i += 10)
    {
        double a = i * M_PI / 180.0;
        auto p = circle.GetPoint (a);
        points.push_back (p);

        auto d = circle.GetDerivative(a);
        derivs.push_back (d);
    }

    SvgWriter svgWriter ("circle.svg", 100, 100);
    svgWriter.SetDerivatives ( points, derivs );
    svgWriter.SetPoints (points);
}

void PrintEllipse ()
{
    Aciz::Ellipse ellipse (40, 10);
    vector<Aciz::Point> points;
    vector<Aciz::Point> derivs;

    for (int i = 0; i <= 360; i += 10)
    {
        double a = i * M_PI / 180.0;
        auto p = ellipse.GetPoint (a);
        points.push_back (p);

        auto d = ellipse.GetDerivative(a);
        derivs.push_back (d);
    }

    SvgWriter svgWriter ("ellipse.svg", 100, 100);
    svgWriter.SetDerivatives (points, derivs);
    svgWriter.SetPoints (points);
}

void PrintHelix ()
{
    Aciz::Helix helix (15, 10);
    vector<Aciz::Point> points;
    vector<Aciz::Point> derivs;

    for (int i = 0; i <= 360 * 5; i += 15)
    {
        double a = i * M_PI / 180.0;
        auto p = helix.GetPoint (a);
        points.push_back (p);

        auto d = helix.GetDerivative (a);
        derivs.push_back (d);
    }
    {
        SvgWriter svgWriter ("helix_xy.svg", 100, 100);
        svgWriter.SetDerivatives (points, derivs);
        svgWriter.SetPoints (points);
    }

    {
        for ( auto& p : points )
            p.y = p.z;
        for ( auto& p : derivs )
            p.y = p.z;

        SvgWriter svgWriter ("helix_xz.svg", 100, 100);
        svgWriter.SetDerivatives (points, derivs);
        svgWriter.SetPoints (points);
    }
}

int main ()
{
    PrintCircle ();
    PrintEllipse();
    PrintHelix();
}