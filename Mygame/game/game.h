#ifndef GAME_H
#define GAME_H
#include "Player.h"

#include <QGraphicsView>
#include <QMouseEvent>

class Game:public QGraphicsView
{
public:
    Game();

    void mouseMoveEvent (QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene * scene;
    Player* player;

};

#endif // GAME_H
