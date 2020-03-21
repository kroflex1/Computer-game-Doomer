#ifndef FIRSTAIDKIT_H
#define FIRSTAIDKIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class FirstAidKit:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    FirstAidKit(QGraphicsItem * parent=0);
    QTimer* checkTime;

public slots:
    void conditionCheck();

};


#endif // FIRSTAIDKIT_H
