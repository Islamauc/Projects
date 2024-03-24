#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QBrush>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPixmap>
#include <QRandomGenerator>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include "level.h"
#include "mainwindow.h"
#include "next_level.h"

class game : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  game();
  QGraphicsScene* getscene();

private:
  QGraphicsScene* scene;
  QGraphicsView* view;
  Level* level1;

  QTimer* timer;
  int n;
  bool enter;
  Next_Level* next_level;
public slots:
  void start();
};

#endif // GAME_H
