#include "Blood.h"

#include <QTimer>
#include <QGraphicsScene>
#include <random>

Blood::Blood(QGraphicsItem *parent)
{
    int randomPicture = rand()%3+1;

    if (randomPicture == 1)
    {
        setPixmap(QPixmap(":images/images/blood1.png"));
    }
    else if (randomPicture == 2)
    {
        setPixmap(QPixmap(":images/images/blood2.png"));

    }

    else
    {
        setPixmap(QPixmap(":images/images/blood3.png"));

    }


    QTimer* timeToClear  = new QTimer();
    connect(timeToClear, SIGNAL(timeout()), this, SLOT(clear()));
    timeToClear->start(40000);
}

void Blood::clear()
{
    scene()->removeItem(this);
    delete this;
    return;
}
