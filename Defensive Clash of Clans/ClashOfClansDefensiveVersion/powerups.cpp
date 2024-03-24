#include "powerups.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QtCore>
#include <QCursor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <QTimer>
#include <QWidget>

powerups::powerups(int m , int h)
{
    r=m;
    c=h;
    QPixmap powerup(":/powerup1.png");
    powerup=powerup.scaledToHeight(50);
    powerup=powerup.scaledToWidth(50);
    setPixmap(powerup);
    setPos(50+50*r,50+50*c);
}

bool powerups::gethit(){
    return hit;
}

void powerups::sethit(bool h){
    hit = h;
}

//void powerups::remove(){

//     hit = true;
//    scene()->removeItem(this);
//    //this->deleteLater();

//}
