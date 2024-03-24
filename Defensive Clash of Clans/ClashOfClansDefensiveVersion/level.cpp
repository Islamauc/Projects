#include "level.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QTextStream>
#include "bullet.h"
#include "castle.h"
#include "enemytroops.h"
#include "fence.h"
#include "gameover.h"
#include "timer.h"
#include "powerups.h"

Level::Level(int enemy_hp)
{
  view = new QGraphicsView();
  scene = new QGraphicsScene();
  view->setWindowTitle("The Game");
  bullet_damage = 1000;
  this->enemy_hp = enemy_hp;
  start();
}
Level::~Level()
{
  delete view;
  delete scene;
  delete troop_timer;
  delete bullet_timer;
  delete timer;
  delete castle;
  delete C;
  delete poweruptimer;
  delete score;
  for(int i=0;i<fences.size();i++)
      delete fences[i];
}
void Level::start()
{
  Timer* timer;
  timer = new Timer();
  QFont f;
  f.setPointSize(20);
  timer->setFont(f);
  timer->setPos(100, 100);
  timer->setPlainText("5:00");
  this->timer = timer;
  QFile file2(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/map (1).txt");
  file2.open(QIODevice::ReadOnly);
  QTextStream stream2(&file2);
  QString x;
  int y = 0;
  while (!stream2.atEnd()) {
    stream2 >> x;
    int z = x.toInt();
    if (z == 2)
      y++;
  }
  int k = 0;
  QVector<fence*> fences;
  fences.resize(y);
  for (int i = 0; i < y; i++) {
    fences[i] = new fence();
  }
  this->fences = fences;
  QFile file3(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/map (1).txt");
  file3.open(QIODevice::ReadOnly);
  QTextStream stream3(&file3);
  QString line;
  int rows(0);
  while (!stream3.atEnd()) {
    line = stream3.readLine();
    rows++;
  }
  QFile file4(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/map (1).txt");
  file4.open(QIODevice::ReadOnly);
  QTextStream stream4(&file4);
  QString line2;
  int columns(0);
  while (!stream4.atEnd()) {
    line2 = stream4.readLine();
    columns++;
  }

  row = rows;
  column = columns;
  QFile file(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/map (1).txt");
  file.open(QIODevice::ReadOnly);
  QVector<QVector<int>> boarddata;
  boarddata.resize(row);

  for (int i = 0; i < row; i++) {
    boarddata[i].resize(column);
  }
  QTextStream stream(&file);
  QString temp;
  Castle* Mcastle = new Castle();
  //enemytroops troop;

  QPixmap grass(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/download (1).jpeg");
  grass = grass.scaledToHeight(50);
  grass = grass.scaledToWidth(50);
  QVector<std::pair<int, int>> v;
  QFile file6(
      "C:/Users/Power/OneDrive/Desktop/PRJ (7)/PRJ/ClashOfClansDefensiveVersion/map (1).txt");
  file6.open(QIODevice::ReadOnly);
  QTextStream stream6(&file6);

  QVector<QVector<QGraphicsPixmapItem*>> boardimages;
  boardimages.resize(rows);

  for (int i = 0; i < rows; i++) {
    boardimages[i].resize(columns);
    for (int j = 0; j < columns; j++) {
      boardimages[i][j] = new QGraphicsPixmapItem(nullptr);
    }
  }

  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      boardimages[i][j]->setPixmap(grass);
      boardimages[i][j]->setPos(50 + 50 * j, 50 + 50 * i);
      scene->addItem(boardimages[i][j]);
    }

  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      stream >> temp;
      boarddata[i][j] = temp.toInt();
    }
  cannon* MAcannon = new cannon(boarddata);

  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      stream6 >> temp;
      if (boarddata[i][j] == 0) {
	v.push_back({i, j});
      }
    }

  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      if (boarddata[i][j] == 1) {
	Mcastle->set(i, j);

      } else if (boarddata[i][j] == 2) {
	fences[k]->set(i, j);
	k++;

      } else if (boarddata[i][j] == 3) {
	MAcannon->set(i, j);
      }
      boardimages[i][j]->setPos(50 + 50 * j, 50 + 50 * i);
      scene->addItem(boardimages[i][j]);
    }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (boarddata[i][j] == 0 || boarddata[i][j] == 5)
	boardimages[i][j]->setPixmap(grass);
    }
  }
  this->boarddata = boarddata;

  troop_timer = new QTimer(this);
  connect(troop_timer, SIGNAL(timeout()), this, SLOT(create_troop()));
  troop_timer->start(1000);
  bullet_timer = new QTimer(this);

  poweruptimer = new QTimer(this);
  connect(poweruptimer,SIGNAL(timeout()),this, SLOT(create_powerup()));
  poweruptimer->start(8000);

  connect(bullet_timer, SIGNAL(timeout()), this, SLOT(create_bullet()));
  bullet_timer->start(500);
  C = MAcannon;
  castle = Mcastle;
  this->r = Mcastle->getr();
  this->c = Mcastle->getc();
  this->s = MAcannon->getr();
  this->m = MAcannon->getc();
  this->v = v;

  QVector<QVector<int>> graph;
  graph.resize(row);
  for (int i = 0; i < row; i++) {
    graph[i].resize(column);
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      if (boarddata[i][j] == 0 || boarddata[i][j] == 5 || boarddata[i][j] == 3)
	graph[i][j] = 10;
      if (boarddata[i][j] == 2)
	graph[i][j] = fences[1]->gethp();
    }
  }

  score = new QGraphicsTextItem();
  score->setPos(100, 150);
  score->setPlainText("Score: " + QString::number(num_troop_killed));
  QFont f1;
  f1.setPointSize(20);
  score->setFont(f1);
  scene->addItem(score);
  this->graph = graph;
  QTimer* updateGraph = new QTimer(this);
  connect(updateGraph, SIGNAL(timeout()), this, SLOT(update_graph()));
  if (MAcannon->isDestroyed()) {
    bullet_timer->stop();
  }
  C->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
  C->setFocus();
  for (int i = 0; i < y; i++) {
    scene->addItem(fences[i]);
  }

  scene->addItem(timer);
  scene->addItem(Mcastle);
  scene->addItem(Mcastle->getrectangle());
  scene->addItem(Mcastle->getHealthBar());
  scene->addItem(MAcannon);
  scene->addItem(MAcannon->getrectangle());
  scene->addItem(MAcannon->getHealthBar());
  view->setScene(scene);
  view->setFixedSize(50 * get_rows(), 50 * get_columns());
  view->show();
}

QGraphicsScene* Level::getscene()
{
  return scene;
}

void Level::create_troop()
{
  int front = 0;
  QRandomGenerator* generator;
  generator = QRandomGenerator::global();
  int randomNumberInt = generator->bounded(0, v.size());

  front = randomNumberInt;

  enemytroops* enemy;
  enemy = new enemytroops(C, graph);
  enemy->sethp(enemy_hp);
  enemy->set(v[front].first, v[front].second);
  enemy->set2(r, c);

  scene->addItem(enemy);
  //  if (enemy->isDestroyed()) {
  //    num_troop_killed++;
  //    qDebug() << QString::number(num_troop_killed);
  //  }

  if (Loss()) {
    this->view->hide();
    gameOver* Over = new gameOver(NULL, 1);
    //Over->show();
    troop_timer->stop();
  }
  if (Win()) {
    this->view->hide();
    //    gameOver* Over = new gameOver(NULL, 2);
    troop_timer->stop();
  }
}



void Level:: create_powerup()
{
  QRandomGenerator* generator;
  generator = QRandomGenerator::global();
  int randomNumberInt = generator->bounded(0, v.size());

  powerups* powerup;
  powerup= new powerups(v[randomNumberInt].first, v[randomNumberInt].second );
  scene->addItem(powerup);

}



void Level::create_bullet()
{
  bullet* sbullet;
  sbullet = new bullet(bullet_damage, castle);
  sbullet->set(C->getc(), C->getr());
  scene->addItem(sbullet);
  if (C->isDestroyed()) {
    bullet_timer->stop();
  }
  score->setPlainText("Score: " + QString::number(enemytroops::get_num_of_troops()));
  if(enemytroops::get_num_of_troops2()==20)
  {
    this->bullet_damage += 0.1 * bullet_damage;
    enemytroops::set_num_of_troops2();
  }
  //  bullets.push_back(*sbullet);
  //  QVector<bullet>::iterator it;
  //  it = bullets.begin();
  //  //num_troop_killed = bullets[0].get_num_of_troops();
  //  num_troop_killed = it->get_num_of_troops();
  //  for (; it != bullets.end(); it++) {
  //    if (it->get_num_of_troops() > num_troop_killed)
  //      num_troop_killed = it->get_num_of_troops();
  //  }
  //  for (int i = 0; i < bullets.size(); i++) {
  //    if (bullets[i].get_num_of_troops() > num_troop_killed)
  //      num_troop_killed = bullets[i].get_num_of_troops();
  //  }
  //  qDebug() << QString::number(num_troop_killed);
}
int Level::get_columns()
{
  return column;
}
int Level::get_rows()
{
  return row;
}
int Level::get_num_troop_killed()
{
  return num_troop_killed;
}
void Level::set_num_troop_killed(int num_troop_killed1)
{
  num_troop_killed = num_troop_killed1;
}
bool Level::Loss()
{
  if (castle->isDestroyed()) {
    return true;
  }
}
bool Level::Win()
{
  if (timer->get_time_remaining() <= 0) {
    return true;
  }
  return false;
}
int Level::get_enemy_hp()
{
  return enemy_hp;
}
bool Level::get_level()
{
  return next_level;
}
int Level::num_troop_killed = 0;
void Level::update_graph()
{
  int k = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      if (boarddata[i][j] == 2 && k != fences.size()) {
	graph[i][j] = fences[k]->gethp();
	k++;
      }
    }
  }
}
