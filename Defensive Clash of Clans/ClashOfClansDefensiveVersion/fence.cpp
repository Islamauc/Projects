#include "fence.h"

fence::fence()
{
  HP = 10000;
}

void fence:: set(int m,int h)
{
    r=m;
    c=h;

    QPixmap Fence(":/download.png");
    Fence=Fence.scaledToHeight(50);
    Fence=Fence.scaledToWidth(50);
    setPixmap(Fence);
    setPos(50+50*c,50+50*r);
}
void fence :: setr(int row)
{
    r=row;
}
void fence :: setc(int col)
{
    c=col;
}
int fence ::getr()
{
    return r;
}
int fence::getc()
{
    return c;
}

void fence::sethp(int Hp)
{
    HP=Hp;
}
int fence::gethp()
{
    return HP;
}
void fence::damage(int amount) {
    HP -= amount;
    if (HP <= 0)
    {

    }
}


bool fence::isDestroyed()
{
    if(HP<= 0)
        return true;
    else
        return false;
}
