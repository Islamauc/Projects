#ifndef CASTLE_H
#define CASTLE_H
#include <QGraphicsRectItem>
#include <QColor>
#include<QGraphicsPixmapItem>
#include<QGraphicsPixmapItem>
class Castle : public QGraphicsPixmapItem
{
public:
    Castle();
    ~Castle();
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void  set(int m,int h);
    void sethp(int Hp);
    int gethp();
    void get_damage(int amount);
    bool isDestroyed();

    QGraphicsRectItem *getrectangle();
    QGraphicsRectItem* getHealthBar();
    void setHealthbar(int hp);
    double getHPorigin();

  private:
    int r;
    int c;
    int HP;
    double hp_origin;
    QGraphicsRectItem* rect;
    QGraphicsRectItem* hbar;
};

#endif // CASTLE_H
