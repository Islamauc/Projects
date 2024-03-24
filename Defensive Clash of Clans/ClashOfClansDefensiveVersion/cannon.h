#ifndef CANNON_H
#define CANNON_H
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QColor>
#include<QGraphicsPixmapItem>
class cannon : public QGraphicsPixmapItem
{
private:
    int HP;
    int r;
    int c;
    QVector<QVector<int>> boarddata;
    double hp_origin;
    QGraphicsRectItem* rect;
    QGraphicsRectItem* hbar;

  public:
    cannon(QVector<QVector<int>>& boarddata);
    ~cannon();
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void set(int m, int h);
    void sethp(int Hp);
    int gethp();
    void get_damage(int amount);
    bool isDestroyed();
    void set_data(int r, int c);
    QGraphicsRectItem* getrectangle();
    QGraphicsRectItem* getHealthBar();
    QGraphicsPixmapItem* cannonImage;
    void setHealthbar(int hp);
    int r_origin;
    int c_origin;
  public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // CANNON_H
