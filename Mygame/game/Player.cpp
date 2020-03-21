#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyGunner.h"
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

    fullHealth = 2000;// максимальное здоровье
    health  = fullHealth;//текущее здоровье

    timeSpawnCommonEnemy = 1500; // время в мс через которе спавнится Enemy


}

void Player::medication(int amountHealth)
{
    if (health + amountHealth > fullHealth)
    {
        health = fullHealth;
        game->health->setPos(game->health->x(), 688);
    }
    else
    {
        health+=amountHealth;
        float persent =amountHealth /  (fullHealth/100);
        game->health->setPos(game->health->x(), game->health->y() - persent*(212/100));
    }


}


void Player::spawnEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

    //уменьшаю время между спавнами противников Enemy
    if (timeSpawnCommonEnemy<=350)
    {
        game->timeSpawnEnemy->setInterval(350);
    }

    else
    {
        timeSpawnCommonEnemy -= 15;
        game->timeSpawnEnemy->setInterval(timeSpawnCommonEnemy);
    }

}

void Player::spawnEnemyGunner()
{
    EnemyGunner* enemyGunner = new EnemyGunner();
    scene()->addItem(enemyGunner);
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
        qDebug()<<"Игра окончена";
    }
}



