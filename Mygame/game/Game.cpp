#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <QTimer>
#include <QGraphicsTextItem>
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


    //спавн противников
    QTimer* spawnTime = new QTimer();
    connect(spawnTime, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    spawnTime->start(2000);


    //создаю курсор
    QCursor cursor = QCursor(QPixmap(":/images/images/cursor.png"));
    setCursor(cursor);

    //отслеживание мыши без её нажатия
    setMouseTracking(true);

    //проигрывание музыки
    QMediaPlayer* mainMusic = new QMediaPlayer();
    mainMusic->setMedia(QUrl("qrc:/sounds/sounds/mainMusic.mp3"));
    mainMusic->play();

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

    QPointF startPos = QPointF(player->x(),player->y());//место откуда вылетает пуля

    Bullet* bullet = new Bullet();
    bullet->setPos(startPos);
    scene->addItem(bullet);

    QLineF ln(bullet->pos(), QCursor::pos());
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);

}


