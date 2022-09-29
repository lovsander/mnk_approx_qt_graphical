#ifndef SOURCEDATA_H
#define SOURCEDATA_H
#include <QObject>
#include <QList>
#include <QPointF>
#include <QRect>
#include "paintscene.h"

//Для хранения исходных данных реализовать класс SourceData;
class SourceData : public QObject
{
     Q_OBJECT
public:
    explicit SourceData(QObject *parent = nullptr);
    void SetScene(paintScene *scene);
    bool CheckPointValidity(QPointF pnt);
    bool static CheckStringValidity(QString sval);
    QString GetLastErrorMessage();
    bool AddPoint(QPointF pnt);
    int GetPointsCount();
    QList<QPointF> GetPointList();
    void SetRanges(QRect ranges);
    QRect GetRanges();
    void Clear();
public slots:
    void CreatePoint(QPointF pnt);
private:
    QList<QPointF> points;
    QString ErrMessage;
    QRect ranges;
    paintScene *scene;
};


#endif // SOURCEDATA_H
