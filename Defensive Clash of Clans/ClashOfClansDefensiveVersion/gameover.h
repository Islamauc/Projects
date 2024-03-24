#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
class gameOver;
}

class gameOver : public QMainWindow
{
    Q_OBJECT

public:
  explicit gameOver(QWidget *parent, int x);
  ~gameOver();

private:
  Ui::gameOver *ui;
};

#endif // GAMEOVER_H
