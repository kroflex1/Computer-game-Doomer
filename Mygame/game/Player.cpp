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



extern Game* game;
Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //задаю спрайт для персонажа
    setPixmap(QPixmap(":/images/images/player.png"));

    health  = 10;


}


void Player::spawnEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

    QMediaPlayer* soundSpawn = new QMediaPlayer();
    soundSpawn->setMedia(QUrl("qrc:/sounds/sounds/monsterSpawn.mp3"));
    soundSpawn->play();

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

void Player::damage()
{
    health -=1;
    game->health->setPos(game->health->x(), game->health->y() + 21.2 );

    if (health <= 0)
    {
        game->gameOver();
    }
}



