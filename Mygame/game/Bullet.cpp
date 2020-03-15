#include "Bullet.h"


#include <QPixmap>
#include <Enemy.h>

#include <QTimer>
#include <QMediaPlayer>
#include <qmath.h> // qSin, qCos, qTan
#include <QList>
#include <QGraphicsScene>



Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":images/images/bullet.png"));

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

}


void Bullet::move(){
    int speed = 60;
    double theta = rotation();

    double dy = speed * qSin(qDegreesToRadians(theta));
    double dx = speed * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


    //проверка на вылет за границу
    if (x() > 1650 or x() < -50 or y() > 950 or y() < -50)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }


}
