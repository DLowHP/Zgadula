#include "GameFinish.h"
#include "ui_GameFinish.h"

GameFinish::GameFinish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFinish)
{
    ui->setupUi(this);
}

GameFinish::~GameFinish()
{
    delete ui;
}

void GameFinish::setMsg(QString msg)
{
    ui->msg->setText(msg);
}

void GameFinish::setGuessedNumber(int value)
{
    ui->guessedNumber->setText(QString::number(value));
}

void GameFinish::setGuessedIn(int value)
{
    ui->guessedIn->setText(QString::number(value));
}

void GameFinish::on_btnContinue_clicked()
{
    emit returnToMenu();
}

void GameFinish::on_btnFinish_clicked()
{
    emit exitApp();
}
