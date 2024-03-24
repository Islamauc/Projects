#ifndef NEXT_LEVEL_H
#define NEXT_LEVEL_H

#include <QMainWindow>

namespace Ui {
class Next_Level;
}

class Next_Level : public QMainWindow
{
  Q_OBJECT

public:
  explicit Next_Level(QWidget *parent, int n);
  bool get_level();
  ~Next_Level();

private slots:
  void on_pushButton_clicked();

private:
  Ui::Next_Level *ui;
  int n;
  bool next;
};

#endif // NEXT_LEVEL_H
