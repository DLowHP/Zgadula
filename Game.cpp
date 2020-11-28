#include "Game.h"
#include "ui_Game.h"

#include <QRandomGenerator>
#include <QKeyEvent>

#define DEBUG

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    randomNumber = QRandomGenerator::global()->bounded(rangeMin, rangeMax);
    connect(ui->btnCheck, SIGNAL(clicked()), this, SLOT(check()));
}

Game::~Game() { delete ui; }

void Game::setValues(QString playerName, int rangeMin, int rangeMax)
{
    this->playerName = playerName;
    this->rangeMin = rangeMin;
    this->rangeMax = rangeMax;
}

void Game::setupGame()
{
    remainingAttempts = 10;
    attempts = 0;
    ui->attemptsCount->setText(QString::number(remainingAttempts));

    ui->hint->setText(NULL);

    randomNumber = QRandomGenerator::global()->bounded(rangeMin, rangeMax);

    input = 0;
    ui->display->display(0);

    awaitingInput = false;
    playerWon = false;

    ui->history->clear();
    historyList.clear();
}

bool Game::getGameState()
{
    return playerWon;
}

int Game::getGuessedNumber()
{
    return randomNumber;
}

int Game::getGuessedIn()
{
    return attempts;
}

void Game::check()
{
    attempts++;
    if (input < randomNumber){
        ui->hint->setText("Podana liczba jest za mala!");
        remainingAttempts--;
    }
    else if (input > randomNumber) {
        ui->hint->setText("Podana liczba jest za duza!");
        remainingAttempts--;
    }
    else if (input == randomNumber) {
        playerWon = true;
        remainingAttempts--;
        ui->attemptsCount->setText(QString::number(remainingAttempts));
        finishGame();
        return;
    }

    ui->attemptsCount->setText(QString::number(remainingAttempts));
    awaitingInput = true;

    historyList.append(input);

    ui->history->setText(ui->history->toPlainText() + QString::number(attempts) + ". " + QString::number(input) + "\n");

    if (remainingAttempts == 0) { finishGame(); }
}

void Game::finishGame()
{
    emit gameFinished();
}


void Game::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key::Key_0: { inputNumber(0); break; }
    case Qt::Key::Key_1: { inputNumber(1); break; }
    case Qt::Key::Key_2: { inputNumber(2); break; }
    case Qt::Key::Key_3: { inputNumber(3); break; }
    case Qt::Key::Key_4: { inputNumber(4); break; }
    case Qt::Key::Key_5: { inputNumber(5); break; }
    case Qt::Key::Key_6: { inputNumber(6); break; }
    case Qt::Key::Key_7: { inputNumber(7); break; }
    case Qt::Key::Key_8: { inputNumber(8); break; }
    case Qt::Key::Key_9: { inputNumber(9); break; }
    case Qt::Key::Key_Backspace: { inputNumber(-1); break; }
    case Qt::Key::Key_Enter: { check(); break; }
#ifdef DEBUG
    case Qt::Key::Key_F7: { ui->hint->setText(QString::number(randomNumber)); break; }
#endif
    }
}

void Game::inputNumber(int value)
{
    if (awaitingInput) {
        input = 0;
        ui->display->display(0);
        awaitingInput = false;
    }
    if (value >= 0) {
        input *= 10;
        input += value;
        ui->display->display(input);
    }
    else {
        input /= 10;
        ui->display->display(input);
    }
}
