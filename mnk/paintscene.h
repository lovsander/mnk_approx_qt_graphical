#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    void drawAxes();
    void drawPoint(QPointF pnt, QColor color =Qt::darkGray);
    void drawTrend(double a, double b);
    void clearAll();
signals:
    void CreatePoint(QPointF);
private:
    QPointF     point;
private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PAINTSCENE_H
