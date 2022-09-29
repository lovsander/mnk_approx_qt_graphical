#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    void drawAxes();
    void drawPoint(QPointF pnt, QColor color =Qt::blue);
    void drawTrend(double a, double b);
    void clearAll();
signals:
    void CreatePoint(QPointF);
    void PointDrawn(QPointF);
private:
    QPointF     point;
    QGraphicsLineItem *trend;
private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PAINTSCENE_H
