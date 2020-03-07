#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Health:public QObject, public QGraphicsPixmapItem
{
public:
    Health();

};

#endif // HEALTH_H
