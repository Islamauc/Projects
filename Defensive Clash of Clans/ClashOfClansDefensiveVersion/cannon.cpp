#include "cannon.h"
#include <QKeyEvent>
#include <QBrush>
cannon::cannon(QVector<QVector<int>> &boarddata)
{
  this->boarddata = boarddata;
  HP = 10000;
  hp_origin = HP;

}
cannon::~cannon()
{
  delete rect;
  delete hbar;
}
void cannon :: setr(int row)
{
    r=row;
}
void cannon :: setc(int col)
{
    c=col;
}
int cannon ::getr()
{
    return r;
}
int cannon::getc()
{
    return c;
}
void cannon:: set(int m,int h)
{
    r=m;
    c=h;
    QPixmap Cannon(":/result (1).png");
    Cannon=Cannon.scaledToHeight(50);
    Cannon=Cannon.scaledToWidth(50);
    setPixmap(Cannon);
    setPos(50 + 50 * r, 50 + 50 * c);
    r_origin=r;
    c_origin=c;
    QGraphicsRectItem *rectangle = new QGraphicsRectItem(50+r*50, 50+(c-0.5)*50, 50, 8); // (x, y, width, height)
    QGraphicsRectItem *healthbar = new QGraphicsRectItem(50+r*50, 50+(c-0.5)*50, 50, 8); // (x, y, width, height)
    rect = rectangle;
    hbar = healthbar;

    hbar->setBrush(QBrush(Qt::green));
    rect->setBrush(QBrush(Qt::white));



}
void cannon::sethp(int Hp)
{
    HP=Hp;
}
int cannon::gethp()
{
    return HP;
}
void cannon::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0)
    {
    }
    setHealthbar(HP);

}
bool cannon::isDestroyed()
{
    if (HP <= 0)
      return true;
    else
      return false;
}
void cannon::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Up && boarddata[c - 1][r] != 2 /*&& c < boarddata[1] < QVector<int> )*/)
      c--;
    if (event->key() == Qt::Key_Down && boarddata[c + 1][r] != 2)
      c++;
    if (event->key() == Qt::Key_Left && boarddata[c][r - 1] != 2)
      r--;
    if (event->key() == Qt::Key_Right && boarddata[c][r + 1] != 2)
      r++;

    /*hbar->setRect(50+getr()*50, 50+(getc()-0.5)*50 ,gethp(), 8 );//    hbar->setPos(50 + 50 * r, 50 + 50 * c);
    rect->setRect(50+getr()*50, 50+(getc()-0.5)*50 ,gethp(), 8 )*/;//
    setPos(50 + 50 * r, 50 + 50 * c);


}
/* }
}*/
void cannon::set_data(int r1, int c1)
{
    this->boarddata[r1][c1] = 0;
}


QGraphicsRectItem* cannon:: getrectangle(){
    return rect;
}
QGraphicsRectItem* cannon::getHealthBar(){
    return hbar;
}
void cannon::setHealthbar(int hp){

    double w = hp/1000.0;
    hbar->setRect(50+r_origin*50, 50+(c_origin-0.5)*50, w*5, 8 );
    if (hp == 0){
      rect->setRect(50+r_origin*50, 50+(c_origin-0.5)*50, 0, 8);
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

}

