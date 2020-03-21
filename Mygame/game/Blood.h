#ifndef BLOOD_H
#define BLOOD_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Blood: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Blood(QGraphicsItem * parent=0);
public slots:
    void clear();
};

#endif // BLOOD_H
