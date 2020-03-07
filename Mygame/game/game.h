#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Health.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QTimer>

class Game:public QGraphicsView
{
public:
    Game();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void gameOver();


    QGraphicsScene * scene;
    Player* player;
    Health* health;

    QTimer *timeShoot;

};

#endif // GAME_H
