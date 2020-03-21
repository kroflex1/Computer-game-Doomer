#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Bullet.h"
#include "QObject"

class EnemyBullet:public Bullet
{
    Q_OBJECT
public:
    EnemyBullet();
public slots:
    void move();
};

#endif // ENEMYBULLET_H
