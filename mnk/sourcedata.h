#ifndef SOURCEDATA_H
#define SOURCEDATA_H
#include <QList>
#include <QPointF>
#include <QRect>
//Для хранения исходных данных реализовать класс SourceData;
class SourceData
{
private:
    QList<QPointF> points;
    QString ErrMessage;
    QRect ranges;
public:
    SourceData();
    bool CheckPointValidity(QPointF pnt);
    bool static CheckStringValidity(QString sval);
    QString GetLastErrorMessage();
    bool AddPoint(QPointF pnt);
    int GetPointsCount();
    bool GetPoint(int n ,QPointF *pnt) ;
    double GetPoint_x(int n);
    double GetPoint_y(int n);
    void SetRanges(QRect ranges);
    QRect GetRanges();
};


#endif // SOURCEDATA_H
