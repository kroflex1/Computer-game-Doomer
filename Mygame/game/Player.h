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
    void keyPressEvent(QKeyEvent * event);
    QList <Enemy> allEnemyes;

public slots:
    void spawnEnemy();
};

#endif // PLAYER_H
