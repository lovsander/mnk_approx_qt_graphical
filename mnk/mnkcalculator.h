#ifndef MNKCALCULATOR_H
#define MNKCALCULATOR_H
#include <QPointF>
#include <QList>

class MnkCalculator
{
public:
    static bool Calc(QList<QPointF> points, double &a, double &b);
};

#endif // MNKCALCULATOR_H
