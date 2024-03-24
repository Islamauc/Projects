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
#include "mainwindow.h"
#include "start.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QGraphicsView view;
    Start s;
    s.show();



    return a.exec();
}

