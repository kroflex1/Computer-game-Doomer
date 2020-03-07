#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Health.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QFont>
#include <QCursor>
#include <QLineF>
#include <QMouseEvent>
#include <QPointF>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>



Game::Game():QGraphicsView(){
    // создание сцены
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,900);
    setBackgroundBrush(QBrush(QImage(":/images/images/bc.png")));
    setScene(scene);


    //отключаю прокрутку у виджета
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600,900);

    //создаю игрока
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable); //делаю фокус на персонажа
    player->setFocus();
    scene->addItem(player);//добавляю на сцену
    player->setPos(800,400);
    player->setObjectName("player");

    //создание полоски жизней
    health = new Health();

    QGraphicsPixmapItem* healthBar = new QGraphicsPixmapItem();
    healthBar->setPixmap(QPixmap(":images/images/healthBar.png"));
    healthBar->setPos(health->x(), health->y()-15);

    scene->addItem(healthBar);
    scene->addItem(health);


    //спавн противников
    QTimer* spawnTime = new QTimer();
    connect(spawnTime, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    spawnTime->start(1000000);

    //создаю курсор
    QCursor cursor = QCursor(QPixmap(":/images/images/cursor.png"));
    setCursor(cursor);

    //отслеживание мыши без её нажатия
    setMouseTracking(true);


    //полноэкранный режим
    showFullScreen();

    show();
}

void Game::mouseMoveEvent (QMouseEvent *event)
{

    QLineF ln(player->pos(), QCursor::pos());
    int angle = -1 * ln.angle();
    player->setRotation(angle);

}

void Game::mousePressEvent(QMouseEvent *event)
{

    timeShoot = new QTimer();
    timeShoot->start(100);
    connect(timeShoot, SIGNAL(timeout()), player, SLOT(createBullet()));

}

void Game::mouseReleaseEvent(QMouseEvent *event)
{
    timeShoot->stop();
}

void Game::gameOver()
{
    close();
}

void Game::keyPressEvent(QKeyEvent *event)
{

        // Движение влево
        if (event->key() == Qt::Key_Left)
        {
            if (player->pos().x() > 0)
            {
                player->setPos(player->x()-10, player->y());
            }
        }
        //Движение вправо
        else if (event->key() == Qt::Key_Right)
        {
            if (player->pos().x() < 1424)
            {
                player->setPos(player->x()+10, player->y());
            }
        }
        //Движение вверх
        else if (event->key() == Qt::Key_Up)
        {
            if (player->pos().y() > 0)
            {
                player->setPos(player->x(), player->y()-10);
            }
        }
        //Движение вниз
        else if (event->key() == Qt::Key_Down)
        {
            if (player->pos().y() < 790)
            {
                player->setPos(player->x(), player->y()+10);
            }
        }


}






