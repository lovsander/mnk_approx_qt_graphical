#include "mnkcalculator.h"

bool MnkCalculator::Calc(QList<QPointF> points, double &a, double &b)
{
    int n = points.size();
    if(n < 2) return false;

    double X, XX, Y, XY;
    X=XX=Y=XY=0;

    foreach (QPointF pnt, points) {
        X  += pnt.x();
        Y  += pnt.y();
        XX += pnt.x()*pnt.x();
        XY += pnt.x()*pnt.y();
    }
    double a_bottom = ( n*XX - X*X );
    if (a_bottom == 0 ) return false;
    a = (n*XY-X*Y) / a_bottom;
    b = (Y - a*X ) / n;
    return true;
}

