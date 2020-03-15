#include "EnemyGunner.h"
#include "game.h"

#include <QDebug>

extern Game* game;

EnemyGunner::EnemyGunner(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":images/images/enemyGunner.png"));

    //задаю статус EnemyGunner
    statusMove = true;
    statusShoot = false;

    //Меняю статус EnemyGunner
    timeToChangeStatus = new QTimer();
    connect(timeToChangeStatus, SIGNAL(timeout()), this, SLOT(changeStatus()));
    timeToChangeStatus->start(3000);

}

void EnemyGunner::shoot()
{

    setRotation(90);
    qDebug()<<"Shoot";
}

void EnemyGunner::changeStatus()
{
    if (statusMove == true)
    {
        this->shoot();
        statusMove = false;
        statusShoot = true;
        timerMove->stop();
    }

    else
    {
        this->move();
        statusShoot = false;
        statusMove = true;
        timerMove->start();
    }
}



