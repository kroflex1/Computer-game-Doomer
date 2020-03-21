#include "EnemyGunner.h"
#include "EnemyBullet.h"
#include "game.h"

#include <QDebug>
#include <random>
#include <QObject>

extern Game* game;

EnemyGunner::EnemyGunner(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":images/images/enemyGunner.png"));

    setHealth(12);
    setSpeed(4);
    setPrize(50);

    setStartPos();

    //задаю статус EnemyGunner
    statusMove = true;
    statusShoot = false;

    //Меняю статус EnemyGunner
    timeToChangeStatus = new QTimer();
    connect(timeToChangeStatus, SIGNAL(timeout()), this, SLOT(changeStatus()));
    timeToChangeStatus->start(rand()%5000+500);

    timeToFire = new QTimer();
    timeToFire->setInterval(600);
    connect(timeToFire, SIGNAL(timeout()), this, SLOT(shoot()));

}



void EnemyGunner::shoot()
{
    QPointF startPos = QPointF(x(), y());//место откуда вылетает пуля

    EnemyBullet* bullet = new EnemyBullet();
    bullet->setPos(startPos);
    scene()->addItem(bullet);

    QLineF ln(bullet->pos(), game->player->pos());
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);


}

void EnemyGunner::changeStatus()
{
    if (statusMove == true)
    {
        timeToFire->start();
        timerMove->stop();
        statusMove = false;
        statusShoot = true;

    }

    else
    {
        this->move();
        timerMove->start();
        timeToFire->stop();
        statusShoot = false;
        statusMove = true;

    }

    timeToChangeStatus->setInterval(rand()%5000+500);
}

void EnemyGunner::setStartPos()
{
    int randomChoice = rand()%4+1;
    if (randomChoice == 1)
    {
        setPos(rand()%1800 - 300, rand()%1100+1200);//снизу
    }
    else if(randomChoice == 2)
    {
        setPos(rand()%1700 - 250, rand()%-250-300);//сверху
    }
    else if(randomChoice == 3)
    {
        setPos(rand()%1700+1750, rand()%1100+1200); //справа
    }
    else if(randomChoice == 4)
    {
        setPos(rand()%-250-300, rand()%1000+1200); //слева
    }
}




