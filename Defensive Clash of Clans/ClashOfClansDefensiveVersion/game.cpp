
#include "game.h"
#include <QChart>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTextStream>
#include <QTimer>
#include "gameover.h"
#include "next_level.h"
game::game()
{
    view= new QGraphicsView();
    scene=new QGraphicsScene();
    view->setWindowTitle("The Game");
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(start()));
    timer->start(1500);
    level1 = new Level(100);
    n = 0;
    enter = true;
}
void game::start()
{
    if(level1->Loss())
        timer->stop();
    if (n == 4 && level1->Win() ) {
      level1->hide();
      if (!(level1->isVisible())) {
	gameOver* Over = new gameOver(NULL, 2);
	timer->stop();
      }
    } else if (level1->Win() && n < 4) {
      if (enter) {
	next_level = new Next_Level(NULL, n);
	next_level->show();
	enter = false;
      }
      if (next_level->get_level() == true) {
	next_level->hide();
    level1 = new Level(level1->get_enemy_hp() * 5);
	level1->show();
	n++;
	enter = true;
      }
    }
}
QGraphicsScene* game::getscene()
{
    return scene;
}
