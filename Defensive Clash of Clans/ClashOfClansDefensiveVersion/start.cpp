#include "start.h"
#include "game.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
}


void Start::on_pushButton_2_clicked()
{
    this->hide();
    //    username = ui->lineEdit->text();
    //    Level *l = new Level(10000);
    //    l->show();
    game *g = new game();
    g->show();
}
