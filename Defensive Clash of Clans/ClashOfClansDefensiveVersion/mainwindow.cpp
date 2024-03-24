/*#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create main widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create layout
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);

    // Create start button
    QPushButton *startButton = new QPushButton("Start Game", this);
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));

    // Add button to layout
    layout->addWidget(startButton);

    // Set layout for central widget
    centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
}
*/
