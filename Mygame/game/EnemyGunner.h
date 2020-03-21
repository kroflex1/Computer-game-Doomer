#ifndef ENEMYGUNNER_H
#define ENEMYGUNNER_H

#include "Enemy.h"

#include <QTimer>
#include <QObject>

class EnemyGunner:public Enemy
{
    Q_OBJECT
public:
    EnemyGunner(QGraphicsItem * parent=0);
    void setStartPos();
    QTimer* timeToChangeStatus; // отвечает за изменение действия EnemyGunner(например отстановить и начать стрелять)
    QTimer* timeToShoot; //противник стоит и стреляет
    QTimer* timeToFire; //сколкьо проходит времени между вылетами пуль
    bool statusMove;
    bool statusShoot;

public slots:
    void shoot();
    void changeStatus();
};

#endif // ENEMYGUNNER_H
