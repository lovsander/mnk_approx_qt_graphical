#include "sourcedata.h"
#include <QDebug>

SourceData::SourceData(QObject *parent): QObject(parent)
{

}

void SourceData::SetScene(paintScene *scene)
{
    this->scene = scene;
}

bool SourceData::CheckPointValidity(QPointF pnt){
    // out range check

    if (   ( pnt.x() < ranges.x() )
           ||   ( pnt.x() > ranges.width()+ranges.x() )
           ||   ( pnt.y() < ranges.y() )
           ||   ( pnt.y() > ranges.height()+ranges.y() )
           ) {
        ErrMessage="CheckPointValidity : out range";
        return false;
    }
    else return true;
}

bool SourceData::CheckStringValidity(QString sval)
{
    bool ok;
    double fval = sval.toDouble(&ok);
    return ok;
}

QString SourceData::GetLastErrorMessage(){
    return ErrMessage;
}

bool SourceData::AddPoint(QPointF pnt) {
    if(CheckPointValidity(pnt))
    {
        qDebug() << " SourceData::AddPoint " << QString::number(pnt.x())<< QString::number(pnt.y());
        points.append(pnt);
        scene->drawPoint(pnt);
        return true;
    }
    else {
        qDebug() << ErrMessage;
        return false;
    }
}

int SourceData::GetPointsCount()
{
    return points.count();
}

bool SourceData::GetPoint(int n ,QPointF *pnt)
{
    if (n < GetPointsCount()) {
        *pnt = points.at(n);
        return true;
    } else {
        ErrMessage="SourceData::GetPoint: n < GetPointsCount()";
        pnt = nullptr;
        return false;
    }
}

QList<QPointF> SourceData::GetPointList()
{
    return points;
}

void SourceData::SetRanges(QRect ranges)
{
    this->ranges=ranges;
}

QRect SourceData::GetRanges()
{
    return ranges;
}

void SourceData::CreatePoint(QPointF pnt)
{
  AddPoint(pnt);
}
