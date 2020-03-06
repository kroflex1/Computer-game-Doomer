#include "Game.h"
#include "Player.h"
#include "Enemy.h"

#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>



Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //задаю спрайт для персонажа
    setPixmap(QPixmap(":/images/images/player.png"));


}


//Управление персонажем
void Player::keyPressEvent(QKeyEvent *event){

    // Движение влево
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    //Движение вправо
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() < 1410)
        setPos(x()+10,y());
    }
    //Движение вверх
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() > 0)
        setPos(x(),y()-10);
    }
    //Движение вниз
    else if (event->key() == Qt::Key_Down)
    {
        if (pos().y() < 790)
        setPos(x(), y()+10);
    }


    QMediaPlayer* soundWalk = new QMediaPlayer();
    soundWalk->setMedia(QUrl("qrc:/sounds/sounds/walk.mp3"));
    QTimer* walkTime = new QTimer();
    walkTime->start(500);


    if (soundWalk->state() == QMediaPlayer::PlayingState)
    {
         soundWalk->setPosition(0);
    }
    else if (soundWalk->state() == QMediaPlayer::StoppedState)
    {
         soundWalk->play();
    }




}

void Player::spawnEnemy()
{
    Enemy* enemy = new Enemy();
    enemy->setTarget(QPointF(x(), y()) );
    scene()->addItem(enemy);

    QMediaPlayer* soundSpawn = new QMediaPlayer();
    soundSpawn->setMedia(QUrl("qrc:/sounds/sounds/monsterSpawn.mp3"));
    soundSpawn->play();



}



