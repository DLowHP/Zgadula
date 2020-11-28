#include "Scores.h"
#include "ui_Scores.h"

Scores::Scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);
}

Scores::~Scores()
{
    delete ui;
}

void Scores::appendScore(QString playerName, int guessedNumber, int guessedIn)
{
    ui->display->setText(ui->display->toPlainText() + playerName + ": " + QString::number(guessedNumber) + "/" + QString::number(guessedIn) + "\n");
}

void Scores::on_btnReturn_clicked()
{
    emit returnToMenu();
}
