#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QList>

#include "Enemy.h"

class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    QList <Enemy> allEnemyes;

    int health;
    int fullHealth;
    int timeSpawnCommonEnemy;

public slots:
    void medication(int amount);
    void spawnEnemy();
    void spawnEnemyGunner();
    void createBullet();
    void damage(int amountDamage);
};

#endif // PLAYER_H
