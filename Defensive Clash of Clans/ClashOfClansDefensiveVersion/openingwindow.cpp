#include "openingwindow.h"

OpeningWindow::OpeningWindow()
{

}
OpeningWindow::OpeningWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* startButton = new QPushButton("Start", this);
    startButton->setFixedSize(100, 50); // Set button size (optional)

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);

    setCentralWidget(startButton)
