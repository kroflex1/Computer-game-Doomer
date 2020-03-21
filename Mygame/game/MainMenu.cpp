#include "MainMenu.h"
#include "Button.h"

#include <QPointF>
#include <QCursor>
#include <QDebug>


MainMenu::MainMenu():QGraphicsView()
{
    menu = new QGraphicsScene();
    menu->setSceneRect(0,0,1600,900);
    setBackgroundBrush(QBrush(QImage(":/images/images/menuBG.png")));
    setScene(menu);

    //отключаю прокрутку у виджета
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600,900);

    Button* button = new Button();
    button->setPicture(":images/images/buttonPlay.png");
    button->setPos(0,550);
    menu->addItem(button);

    showFullScreen();
}

void MainMenu::keyPressEvent(QKeyEvent *event)
{

    QPoint r(400,400);
    if(QCursor::pos() ==r )
    {
        qDebug()<<"hello";
    }
}
