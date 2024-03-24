#include "timer.h"


Timer::Timer( )
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_display23()));
    timer->start(1000);
    this->setPlainText("5:00");
    time_remaining = 20;
}
void Timer::Timer_display23()
{
    if(time_remaining>0)
    {
        --time_remaining;
        minutes=time_remaining/60;
        seconds=time_remaining % 60;
        if(seconds<10)
        this->setPlainText(QString::number(minutes)+":"+"0"+QString::number(seconds));
        else
        this->setPlainText(QString::number(minutes)+":"+QString::number(seconds));

    }
    else
    {
        timer->stop();
        this->setPlainText("Game Over!");
    }
}
int Timer::get_time_remaining()
{
    return time_remaining;
}


