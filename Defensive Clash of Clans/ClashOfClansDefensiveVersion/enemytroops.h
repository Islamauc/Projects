#ifndef ENEMYTROOPS_H
#define ENEMYTROOPS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "cannon.h"
typedef bool flag;
class enemytroops: public QObject ,public QGraphicsPixmapItem
{
Q_OBJECT
private:
    int HP;
    int damage;
    int r;
    int c;
    int z;
    int a;
    QTimer* timer;
    flag can_move = true;
    QTimer* timer2;
    int changer;
    cannon* C;
    QVector<QVector<int>> graph;
    int rows;
    int cols;
    QVector<QVector<int>> directions
	= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    QVector<std::pair<int, int>> actualPath;
    int des1;
    int des2;
    QVector<std::pair<int, int>>::iterator it;
    int o;
    static int num_of_troops;
    static int num_of_troops2;
    double sum = 0;
    double sum2 = 0;
    //std::pair<int, int>* it;

  public:
    enemytroops(cannon* C, QVector<QVector<int>> graph);
    void setr(int row);
    void setc(int col);
    int getr();
    int getc();
    void set(int m,int h);
    void set2(int z,int a);
    void sethp(int Hp);
    int gethp();
    void create_troop();
    void attackFence();
    void attackCannon();
    void get_damage(int amount);
    void attackCastle();
    bool isDestroyed();
    std::pair<int, int> min_node(const QVector<QVector<int>>& distances,
				 const QVector<QVector<bool>>& processedNodes);
    void findShortestPaths(const QVector<QVector<int>>& grid,
			   const std::pair<int, int>& sourceNode,
			   const std::pair<int, int>& destinationNode);
    static int get_num_of_troops();
    void check();
    static int get_num_of_troops2();
    static void set_num_of_troops2();

  public slots:
    void move();
      void motion();

};

#endif // ENEMYTROOPS_H
