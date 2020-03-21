#include "Button.h"

Button::Button(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{

}

void Button::setPicture(QString fileName)
{
    setPixmap(QPixmap(fileName));
}
