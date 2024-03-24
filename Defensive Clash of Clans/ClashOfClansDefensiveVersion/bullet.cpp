#include "bullet.h"
#include <QCursor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <QTimer>
#include <QWidget>
#include "enemytroops.h"
#include "powerups.h"

bullet::bullet(int damage,Castle* C)
{
    Point=QCursor ::pos();
    timer = new QTimer(this);
    this->damage=damage;
    this->C=C;

}
bullet::~bullet()
{
    delete timer;
}
void bullet::setr(int row)
{
    r=row;
}
void bullet::setc(int col)
{
    c=col;
}
int bullet::getr()
{
    return r;
}
int bullet::getc()
{
    return c;
}
void bullet::set(int m,int h)
{
    r=m;
    c=h;

    QPixmap Bullet(":/Mbullet.png");
    Bullet=Bullet.scaledToHeight(20);
    Bullet=Bullet.scaledToWidth(20);
    setPixmap(Bullet);
    setPos(60 + 50 * c, 50 + 50 * r);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(16);


    float inc_x = (Point.x() - x());
    float inc_y = (Point.y() - y());

    delta_x = inc_x / sqrtf((inc_x * inc_x) + (inc_y * inc_y));
    delta_y = inc_y / sqrtf((inc_x * inc_x) + (inc_y * inc_y));

}
void bullet::move()
{
    attackTroop();
    if (x() < 800 && y() < 800 && y() > 0 && x() > 0) {
      setPos(x() + (delta_x * speed_factor), y() + (delta_y * speed_factor));

    } else {
      scene()->removeItem(this);
      timer->stop();
      this->deleteLater();
    }

    hitpowerup();

}
void bullet::attackTroop()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(enemytroops)) {
	enemytroops *troop = static_cast<enemytroops *>(item);
	troop->get_damage(damage);
	if (troop->isDestroyed()) {
	  //qDebug() << "osama";
	  //num_of_troops++;
	}
      }
    }
}


void bullet::hitpowerup()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(powerups))
      {
    powerups *powerup = static_cast<powerups *>(item);
    if(C->gethp()!= 0){
      C->sethp(C->getHPorigin());
      C->setHealthbar(C->getHPorigin());
      scene()->removeItem(powerup);
    }
      }
    }

}

//int bullet::get_num_of_troops()
//{
//    return num_of_troops;
//}
