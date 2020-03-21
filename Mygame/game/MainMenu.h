#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsView>
#include <QMouseEvent>


#include <Button.h>

class MainMenu:public QGraphicsView
{
public:
    MainMenu();

    QGraphicsScene* menu;

    void keyPressEvent(QKeyEvent * event);

};

#endif // MAINMENU_H
