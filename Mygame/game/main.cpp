#include "Game.h"
#include "MainMenu.h"

#include <QApplication>
#include <QTimer>
#include <QObject>

Game* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainMenu* menu = new MainMenu();
    menu->show();

    return a.exec();
}
