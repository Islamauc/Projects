#include "enemytroops.h"
#include <QApplication>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTime>
#include <QTimer>
#include <QtCore>
#include "cannon.h"
#include "castle.h"
#include "fence.h"




enemytroops::enemytroops(cannon *C, QVector<QVector<int>> graph)
{
    timer = new QTimer(this);
    damage = 100;
    HP = 1000;
    this->C = C;
    this->graph = graph;
    this->rows = this->graph.size();
    this->cols = this->graph[0].size();
}
void enemytroops :: setr(int row)
{
    r=row;
}
void enemytroops :: setc(int col)
{
    c=col;
}
int enemytroops ::getr()
{
    return r;
}
int enemytroops::getc()
{
    return c;
}

void enemytroops::sethp(int Hp)
{
    HP=Hp;
}
int enemytroops::gethp()
{
    return HP;
}
void enemytroops:: set(int m,int h)
{
    r=m;
    c=h;
    QPixmap Enemytroop(":/result (4) (1).png");
    Enemytroop=Enemytroop.scaledToHeight(50);
    Enemytroop=Enemytroop.scaledToWidth(50);
    setPixmap(Enemytroop);
    setPos(50+50*c,50+50*r);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(16);
//    connect(timer2,SIGNAL(timeout()),this,SLOT (motion()));
//    timer2->start(220);
}
void enemytroops::set2(int z, int a)
{
    this->z = z;
    this->a = a;
    findShortestPaths(graph, {r, c}, {z, a});
    it = actualPath.begin() + 1;

}



void enemytroops::motion()
{
    if(can_move)
    {
      if(changer==1)
      {
          QPixmap Enemytroop2(":/troopmotion_1 (1).png");
          Enemytroop2=Enemytroop2.scaledToHeight(52);
          Enemytroop2=Enemytroop2.scaledToWidth(52);
          setPixmap(Enemytroop2);
          changer=2;

      }
      else if(changer==2)
      {
          QPixmap Enemytroop3(":/troopmotion_2 (1).png");
          Enemytroop3=Enemytroop3.scaledToHeight(45);
          Enemytroop3=Enemytroop3.scaledToWidth(45);
          setPixmap(Enemytroop3);
          changer=1;
      }
    }

}

void enemytroops ::move()
{
    attackFence();
    attackCannon();
    attackCastle();
;
    if (it != actualPath.end()) {
      des1 = it->first;
      des2 = it->second;
    }

    double deltax = (50 + des1 * 50 - x());
    double cx = (50 + des1 * 50 - x()) / 180.0;
    sum = sum + cx;
    double cy = (50 + des2 * 50 - y()) / 180.0;
    sum2 = sum2 + cy;
    if ((sum < deltax + 50 && sum > deltax - 50) && it != actualPath.end()) {
      it++;
      sum2 = 0;
      sum = 0;
    }
    if (can_move) {
      setPos(x() + cx, y() + cy);
    }
}





std::pair<int, int> enemytroops::min_node(const QVector<QVector<int>> &distances,
					  const QVector<QVector<bool>> &processedNodes)
{
    int minDistance = INT_MAX;
    std::pair<int, int> minNode;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
	if (!processedNodes[i][j] && distances[i][j] <= minDistance) {
	  minDistance = distances[i][j];
	  minNode = {i, j};
	}
      }
    }

    return minNode;
}

void enemytroops::findShortestPaths(const QVector<QVector<int>> &grid,
				    const std::pair<int, int> &sourceNode,
				    const std::pair<int, int> &destinationNode)
{
    QVector<QVector<int>> distances(rows, QVector<int>(cols, INT_MAX));
    QVector<QVector<bool>> processedNodes(rows, QVector<bool>(cols, false));
    QVector<std::pair<int, int>> path;

    distances[sourceNode.first][sourceNode.second] = 0;

    while (!processedNodes[destinationNode.first][destinationNode.second]) {
      std::pair<int, int> currentNode = min_node(distances, processedNodes);
      processedNodes[currentNode.first][currentNode.second] = true;

      path.push_back(currentNode);

      for (int k = 0; k < 8; k++) {
	int x = currentNode.first + directions[k][0];
	int y = currentNode.second + directions[k][1];

	if (x >= 0 && x < rows && y >= 0 && y < cols && !processedNodes[x][y] && grid[x][y]
	    && distances[currentNode.first][currentNode.second] != INT_MAX
	    && distances[currentNode.first][currentNode.second] + grid[x][y] < distances[x][y]) {
	  distances[x][y] = distances[currentNode.first][currentNode.second] + grid[x][y];
	}
      }
    }

    std::pair<int, int> current = destinationNode;
    QVector<std::pair<int, int>> actualPath;

    while (current != sourceNode) {
      actualPath.insert(actualPath.begin(), current);
      int x = current.first;
      int y = current.second;

      std::pair<int, int> nextNode;
      int minDistance = INT_MAX;

      for (int k = 0; k < 8; k++) {
	int nx = x - directions[k][0];
	int ny = y - directions[k][1];

	if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && distances[nx][ny] < minDistance) {
	  minDistance = distances[nx][ny];
	  nextNode = {nx, ny};
	}
      }

      current = nextNode;
    }

    actualPath.insert(actualPath.begin(), sourceNode);
    this->actualPath = actualPath;
}

void enemytroops::attackFence()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(fence)) {
	can_move = false;
	fence *Fence = static_cast<fence *>(item);
	Fence->damage(damage);
	if (Fence->isDestroyed()) {
	  can_move = true;
	  C->set_data(Fence->getr(), Fence->getc());
	  scene()->removeItem(Fence);
	}
      }
    }
}
void enemytroops::get_damage(int amount)
{
    HP -= amount;
    if (HP <= 0) {
      this->deleteLater();
    }
}
void enemytroops::attackCannon()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(cannon)) {
	can_move = false;
	cannon *c = static_cast<cannon *>(item);
	c->get_damage(damage);
	if (c->isDestroyed()) {
	  can_move = true;
	  scene()->removeItem(c);
	}
      }
    }
}
void enemytroops::attackCastle()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
      if (typeid(*item) == typeid(Castle)) {
	Castle *c = static_cast<Castle *>(item);
	c->get_damage(damage);
	if (c->isDestroyed()) {
	  can_move = true;
	  scene()->removeItem(c);
	}
      }
    }
}
bool enemytroops::isDestroyed()
{
    if (HP <= 0) {
      num_of_troops++;
      num_of_troops2++;
      return true;
    } else
      return false;
}
int enemytroops::num_of_troops = 0;
int enemytroops::get_num_of_troops()
{
    return num_of_troops;
}
int enemytroops::num_of_troops2 = 0;
int enemytroops::get_num_of_troops2()
{
    return num_of_troops2;
}
void enemytroops::set_num_of_troops2()
{
    num_of_troops2=0;
}
