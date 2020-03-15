#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Health.h"
#include "Score.h"

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
    void displayGameOverWindow();


    QGraphicsScene * scene;
    Player* player;
    Health* health;
    Score* score;


    QTimer* timeShoot;
    QTimer* timeSpawn;
    QTimer* timeSpawnEnemyGunner;

};

#endif // GAME_H
