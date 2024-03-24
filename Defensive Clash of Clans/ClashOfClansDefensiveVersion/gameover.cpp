#include "gameover.h"
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPushButton>
#include "ui_gameover.h"

gameOver::gameOver(QWidget *parent, int x)
    : QMainWindow(parent)
    , ui(new Ui::gameOver)
{
  QGraphicsView *view = new QGraphicsView;
  QGraphicsScene *scene = new QGraphicsScene;
  view->setScene(scene);
  ui->setupUi(this);
  QGraphicsTextItem *text;
  text = new QGraphicsTextItem();
  QFont f;
  f.setPointSize(20);
  text->setFont(f);
  text->setPos(100, 100);
  if (x == 2) {
    text->setPlainText("Gameover! You Win!");
    text->setDefaultTextColor(Qt::green);
  } else if (x == 1) {
    text->setPlainText("Gameover! You Lose!");
    text->setDefaultTextColor(Qt::red);
  }
  scene->addItem(text);
  view->setWindowTitle("Gameover");
  view->setFixedSize(600, 600);
  view->show();
}

gameOver::~gameOver()
{
    delete ui;
}
