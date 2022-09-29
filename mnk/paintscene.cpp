#include "paintscene.h"
#include <QDebug>

paintScene::paintScene(QObject *parent)
{
    trend = new QGraphicsLineItem;
}

paintScene::~paintScene()
{
   delete trend;
}

void paintScene::drawAxes()
{
    //axes
    addLine(0,-sceneRect().y(),0,sceneRect().y(), QPen(QBrush(Qt::gray), 1, Qt::DotLine));
    addLine(-sceneRect().x(),0,sceneRect().x(),0, QPen(QBrush(Qt::gray), 1, Qt::DotLine));
}

void paintScene::drawPoint(QPointF pnt, QColor color)
{
    // draw point as ellipse
    addEllipse(pnt.x() - 5,
               pnt.y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(color));
   emit PointDrawn(pnt);
}

void paintScene::drawTrend(double a, double b)
{
    double  y1 = -sceneRect().x()*a+b;
    double  y2 = sceneRect().x()*a+b;
    removeItem(trend); // kill existing and draw new line
    trend = addLine(-sceneRect().x(),y1,sceneRect().x(),y2, QPen(QBrush(Qt::red), 2, Qt::SolidLine));
}

void paintScene::clearAll()
{
    clear();
    drawAxes();
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // save coordinates
    point = event->scenePos();
    //todo
    // invert y axis because screen starts at top and rise coord to bottom
    // further we'll need invert again when draw results at screen
    //point.setY(-point.y());
    emit CreatePoint(point);
}

