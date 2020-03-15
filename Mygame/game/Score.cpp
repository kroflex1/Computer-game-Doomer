#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",45));
}

void Score::increase(int amount){
    score+=amount;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
