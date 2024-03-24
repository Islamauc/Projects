#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QGraphicsTextItem>


class Timer : public QGraphicsTextItem
{
    Q_OBJECT

public:
    explicit Timer();
    int get_time_remaining();
private slots:
    void Timer_display23();
private:
    QTimer *timer;
    int time_remaining;
    int seconds;
    int minutes;
};

#endif // TIMER_H
