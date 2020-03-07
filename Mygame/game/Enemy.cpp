#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "game.h"


#include <QPixmap>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "qmath.h"
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":images/images/enemy.png"));
    setPos(rand()%1600, rand()%900 );

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(setTarget()));
    timer->start(100);

    health = 3;



}

void Enemy::damage()
{
    health-=1;
    if (health == 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

}

QPointF Enemy::setTarget()
{
    this->target = game->player->pos();
}

void Enemy::move()
{

    QLineF ln(pos(), target);
    int angle = -1 * ln.angle();
    setRotation(angle);

    int speed = 10;
    double theta = rotation();

    double dy = speed * qSin(qDegreesToRadians(theta));
    double dx = speed * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


    //проверка на столкновение с пулей

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
            if (typeid(*(colliding_items[i])) == typeid(Bullet))
            {

                // удаляю пулю
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];          
                this->damage();
                return;

            }

            else if (typeid(*(colliding_items[i])) == typeid(Player))
            {
                game->player->damage();
            }
    }



}


