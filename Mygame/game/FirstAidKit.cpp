#include "FirstAidKit.h"
#include "game.h"

#include <QObject>

extern Game* game;

FirstAidKit::FirstAidKit(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":images/images/firstAidKit.png"));

    checkTime = new QTimer();
    checkTime->start(10);
    connect(checkTime, SIGNAL(timeout()), this, SLOT(conditionCheck()));
}

void FirstAidKit::conditionCheck()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Player))
            {
                game->player->medication(100);
                scene()->removeItem(this);
                delete  this;
                return;
            }

    }
}
