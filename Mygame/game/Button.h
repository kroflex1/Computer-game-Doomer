#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>

class Button: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Button(QGraphicsItem * parent=0);
    void setPicture(QString fileName);
};


#endif // BUTTON_H
