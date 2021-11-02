
#include <cmath>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace std;
using namespace Aciz;

void PrintCircle ()
{
    cout<<"Circle:\n";
    vector<string> screen ( 100, string(100, ' ') );

    Circle circle ( 20 );
    for ( int i=0; i<=360; i += 1)
    {
        double a =  i * M_PI / 180.0;
        auto p = circle.GetPoint ( a );
        //cout<<i << " " <<a << " " << p << endl;
        int x = lround (p.x) + 50;
        int y = lround (p.y) + 50;
        screen[y][x] = 'c';
    }

    for ( auto it = screen.rbegin();  it != screen.rend(); it++ )
    {
        cout << *it << endl;
    }
    cout<<"\n\n";
}

void PrintEllipse ()
{
    cout<<"Ellipse:\n";
    vector<string> screen ( 100, string(100, ' ') );

    Ellipse ellipse ( 40, 10 );
    for ( int i=0; i<=360; i += 1)
    {
        double a =  i * M_PI / 180.0;
        auto p = ellipse.GetPoint ( a );
        //cout<<i << " " <<a << " " << p << endl;
        int x = lround (p.x) + 50;
        int y = lround (p.y) + 50;
        screen[y][x] = 'e';
    }

    for ( auto it = screen.rbegin();  it != screen.rend(); it++ )
    {
        cout << *it << endl;
    }
    cout<<"\n\n";

}

void PrintHelix ()
{
    cout<<"Helix:\n";

    vector<string> screen (100, string (200, ' '));
    for (string &s : screen)
        s[100] = '|';

    Helix helix (15, 15);
    for (int i = 0; i <= 360*5; i += 1)
    {
        double a = i * M_PI / 180.0;
        auto p = helix.GetPoint (a);
        //cout<<i << " " <<a << " " << p << endl;
        int x = lround (p.x) + 50;
        int y = lround (p.y) + 50;
        int z = lround (p.z);
        screen[y][x] = 'h';
        if ( z < 100 )
        {
            screen[z][x+100] = 'h';
        }
    }

    for (auto it = screen.rbegin (); it != screen.rend (); it++)
    {
        cout << *it << endl;
    }
    cout<<"\n\n";

}

int main ()
{
    try
    {
        PrintCircle ();
        PrintEllipse ();
        PrintHelix();
    }
    catch ( std::exception& e)
    {
        cerr<<"Std exception: "<<e.what()<<endl;
    }
}