#ifndef FENCE_H
#define FENCE_H
#include<QGraphicsPixmapItem>

class fence :public QGraphicsPixmapItem
{
private:
    int HP;
    int r;
    int c;
public:
    fence();
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void  set(int m,int h);
    void sethp(int Hp);
    int gethp();
    void damage(int amount);
    bool isDestroyed();
};

#endif // FENCE_H
