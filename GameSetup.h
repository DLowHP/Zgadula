#ifndef GAMESETUP_H
#define GAMESETUP_H

#include <QWidget>

namespace Ui {
class GameSetup;
}

class GameSetup : public QWidget
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = nullptr);
    ~GameSetup();

    QString getPlayerName();
    int getRangeMin();
    int getRangeMax();

private slots:
    void on_btnReturn_clicked();

    void on_btnContinue_clicked();

private:
    Ui::GameSetup *ui;

    QString playerName = "Player";
    int rangeMin = 0;
    int rangeMax = 1000;

signals:
    void returnToMenu();
    void setupGame();
};

#endif // GAMESETUP_H
