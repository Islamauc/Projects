#include "next_level.h"
#include "ui_next_level.h"

Next_Level::Next_Level(QWidget *parent, int n)
    : QMainWindow(parent)
    , ui(new Ui::Next_Level)
{
  ui->setupUi(this);
  this->n = n;
}

Next_Level::~Next_Level()
{
  delete ui;
}

void Next_Level::on_pushButton_clicked()
{
  //if (n != 0)
  next = true;
  //  else
  //    next = false;
}
bool Next_Level::get_level()
{
  return next;
}
