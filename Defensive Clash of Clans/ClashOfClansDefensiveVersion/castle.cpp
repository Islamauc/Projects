#include "castle.h"
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QCoreApplication>
#include <QBrush>

Castle::Castle()
{
    HP=100000;
    hp_origin = HP;

}
Castle::~Castle()
{
    delete rect;
    delete hbar;
}
void Castle :: setr(int row)
{
    r=row;
}
void Castle :: setc(int col)
{
    c=col;
}
int Castle ::getr()
{
    return r;
}
int Castle::getc()
{
    return c;
}
double Castle::getHPorigin(){
    return hp_origin;
}

void Castle:: set(int m,int h)
{
    r=m;
    c=h;

    QPixmap castle(":/result.png");
    castle=castle.scaledToHeight(100);
    castle=castle.scaledToWidth(100);
    setPixmap(castle);
    setPos(30 + 50 * c, 30 + 50 * r);
    //setPixmap(castle);

    QGraphicsRectItem *rectangle = new QGraphicsRectItem(50+r*50, 50+(c-0.5)*50, 50, 8); // (x, y, width, height)
    QGraphicsRectItem *healthbar = new QGraphicsRectItem(50+r*50, 50+(c-0.5)*50, 50, 8); // (x, y, width, height)
    rect = rectangle;
    hbar = healthbar;

    hbar->setBrush(QBrush(Qt::green));
    rect->setBrush(QBrush(Qt::white));



}
void Castle::sethp(int Hp)
{
    HP=Hp;
}
int Castle::gethp()
{
    return HP;
}
void Castle::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0)
    {
    }
    setHealthbar(HP);

}

bool Castle::isDestroyed()
{
    if (HP <= 0)
      return true;
    else
      return false;
}

QGraphicsRectItem* Castle:: getrectangle(){
    return rect;
}
QGraphicsRectItem* Castle::getHealthBar(){
    return hbar;
}
void Castle::setHealthbar(int hp){

    double w = hp/10000.0;
    hbar->setRect(50+r*50, 50+(c-0.5)*50, w*5, 8 );
    if (hp == 0){
      rect->setRect(50+r*50, 50+(c-0.5)*50, 0, 8);
    }


    bool red = false;
    if(hp <= hp_origin*0.40)
    {
      hbar->setBrush(QBrush(Qt::red));
      red = true;
    }

    if((hp <= hp_origin*0.75) && (!red))
    {
      hbar->setBrush(QBrush(Qt::yellow));
    }

    if((hp > hp_origin*0.75) && (!red)){
      hbar->setBrush(QBrush(Qt::green));

    }


}
