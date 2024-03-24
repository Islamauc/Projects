#ifndef LEVEL_H
#define LEVEL_H
#include <QApplication>
#include <QBrush>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QObject>
#include <QPixmap>
#include <QRandomGenerator>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include "cannon.h"
#include "castle.h"
#include "fence.h"
#include "mainwindow.h"
#include "timer.h"
class Level : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Level(int enemy_hp);
  int get_rows();
  int get_columns();
  void start();
  static int get_num_troop_killed();
  static void set_num_troop_killed(int num_troop_killed);
  QGraphicsScene* getscene();
  bool Loss();
  bool Win();
  int get_enemy_hp();
  bool get_level();
  void update_graph();
  ~Level();

private:
  QTimer* troop_timer;
  QTimer* poweruptimer;

  int r;
  int c;
  int s;
  int m;
  int column;
  int row;
  cannon* C;
  QTimer* bullet_timer;
  QGraphicsScene* scene;
  Timer* timer;
  Castle* castle;
  int bullet_damage;
  QVector<std::pair<int, int>> v;
  QGraphicsView* view;
  QVector<QVector<int>> boarddata;
  int enemy_hp;
  bool next_level = false;
  QVector<QVector<int>> graph;
  static int num_troop_killed;
  QGraphicsTextItem* score;
  //  int level_score;
  //  QVector<bullet> bullets;
  QVector<fence*> fences;
public slots:

  void create_troop();
  void create_bullet();
  void create_powerup();
};

#endif // LEVEL_H
