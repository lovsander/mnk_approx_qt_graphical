#include "paintscene.h"
#include <QDebug>

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::drawAxes()
{
    //axes
    addLine(0,-240,0,240, QPen(QBrush(Qt::gray), 1, Qt::DotLine));
    addLine(-240,0,240,0, QPen(QBrush(Qt::gray), 1, Qt::DotLine));
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
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // save coordinates
    point = event->scenePos();
    // invert y axis because screen starts at top and rise coord to bottom
    // further we'll need invert again when draw results at screen
    //point.setY(-point.y());
    emit CreatePoint(point);
}

