#include "GameSetup.h"
#include "ui_GameSetup.h"

GameSetup::GameSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSetup)
{
    ui->setupUi(this);
}

GameSetup::~GameSetup()
{
    delete ui;
}

QString GameSetup::getPlayerName()
{
    return playerName;
}

int GameSetup::getRangeMin()
{
    return rangeMin;
}

int GameSetup::getRangeMax()
{
    return rangeMax;
}

void GameSetup::on_btnReturn_clicked()
{
    emit returnToMenu();
}

void GameSetup::on_btnContinue_clicked()
{
    playerName = ui->playerNameInput->text();
    rangeMin = ui->rangeMinInput->value();
    rangeMax = ui->rangeMaxInput->value();
    emit setupGame();
}
