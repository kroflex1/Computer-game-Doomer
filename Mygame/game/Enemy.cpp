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

    health = 3;

    //задаю рандомную позицию
    int randomChoice = rand()%4+1;
    if (randomChoice == 1)
    {
        setPos(rand()%1650 - 80, rand()%900+950);
    }
    else if(randomChoice == 2)
    {
        setPos(rand()%1680 - 80, rand()%-50);
    }
    else if(randomChoice == 3)
    {
        setPos(rand()%1650+1600, rand()%950);
    }
    else if(randomChoice == 4)
    {
        setPos(rand()%-50-100, rand()%950);
    }


    //перевдижение
    timerMove = new QTimer();
    connect(timerMove, SIGNAL(timeout()), this, SLOT(move()));
    timerMove->start(100);

    timeToRotation = new QTimer();
    connect(timerMove, SIGNAL(timeout()), this, SLOT(setTarget()));
    timeToRotation->start(10);

}

void Enemy::damage()
{
    health-=1;
    if (health <= 0)
    {
        game->score->increase(10);

        scene()->removeItem(this);
        delete this;
        return;
    }

}

QPointF Enemy::getTarget()
{
    return target;
}

QPointF Enemy::setTarget()
{
    target = game->player->pos();
    QLineF ln(pos(), target);
    int angle = -1 * ln.angle();
    setRotation(angle);
}

void Enemy::move()
{

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
                game->player->damage(10);
            }
    }

}


