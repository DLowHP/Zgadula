#ifndef GAME_H
#define GAME_H

#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void setValues(QString playerName = "", int rangeMin = 0, int rangeMax = 1000);
    void setupGame();

    bool getGameState();
    int getGuessedNumber();
    int getGuessedIn();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::Game *ui;

    QString playerName = "Player";
    int rangeMin = 0;
    int rangeMax = 1000;

    int remainingAttempts = 10;
    int attempts = 0;
    int randomNumber = 0;
    int input = 0;

    bool awaitingInput = false;
    bool playerWon = false;

    QList<int> historyList;

    void inputNumber(int value);

private slots:
    void check();
    void finishGame();

signals:
    void gameFinished();
};

#endif // GAME_H
