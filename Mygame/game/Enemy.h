#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    void damage();
    void setStartPos();
    int getHealth();
    int setHealth(int num);
    int getSpeed();
    int setSpeed(int num);
    int getPrize();
    int setPrize(int num);

    QPointF getTarget();
    QTimer* timerMove;
    QTimer* timeToRotation;

public slots:
    void move();
    QPointF setTarget();
private:
    QPointF target;//точка к которой должен двигать противник
    int health;
    int speed;
    int prize;
};

#endif // ENEMY_H
