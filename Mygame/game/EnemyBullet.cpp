#include "EnemyBullet.h"
#include "Enemy.h"
#include "Player.h"
#include "game.h"

#include <QGraphicsScene>
#include <qmath.h>
#include <QDebug>

extern Game* game;

EnemyBullet::EnemyBullet()
{
    setPixmap(QPixmap(":images/images/enemyBullet.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

}

void EnemyBullet::move()
{
    int speed = 10;
    double theta = rotation();

    double dy = speed * qSin(qDegreesToRadians(theta));
    double dx = speed * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


    //проверка на вылет за границу
    if (x() > 1650 or x() < -50 or y() > 950 or y() < -50)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Player))
            {
                game->player->damage(25);
            }
    }
}



