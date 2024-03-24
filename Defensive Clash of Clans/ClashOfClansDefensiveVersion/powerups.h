#ifndef POWERUPS_H
#define POWERUPS_H

#include <QGraphicsPixmapItem>
#include <QObject>


class powerups: public QGraphicsPixmapItem
{

private:

    int value;
    int r;
    int c;
    bool hit = false;



public:
    powerups(int m, int h/*,bullet* b*/);
    int getvalue();
    bool gethit();
    void sethit(bool h);

};

#endif // POWERUPS_H
