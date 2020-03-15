#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Health.h"


#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QDebug>



extern Game* game;
Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //задаю спрайт для персонажа
    setPixmap(QPixmap(":/images/images/player.png"));

    fullHealth = 1000;// максимальное здоровье
    health  = 1000;//текущее здоровье

    timeSpawnCommonEnemy = 1500; // время в мс через которе спавнится Enemy


}


void Player::spawnEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

    //уменьшаю время между спавнами противников Enemy
    if (timeSpawnCommonEnemy<=350)
    {
        game->timeSpawn->start(350);
    }

    else
    {
        timeSpawnCommonEnemy -= 15;
        game->timeSpawn->start(timeSpawnCommonEnemy);
    }

}


void Player::createBullet()
{
    QPointF startPos = QPointF(x(), y());//место откуда вылетает пуля

    Bullet* bullet = new Bullet();
    bullet->setPos(startPos);
    scene()->addItem(bullet);

    QLineF ln(bullet->pos(), QCursor::pos());
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);


}

void Player::damage(int amountDamge)
{
    health -=amountDamge;
    float persent =amountDamge / (fullHealth / 100);
    game->health->setPos(game->health->x(), game->health->y()+persent*(212/100) );

    //если здоровье меньше нуля то игра заканчивается
    if (health <= 0)
    {
        game->gameOver();
    }
}



