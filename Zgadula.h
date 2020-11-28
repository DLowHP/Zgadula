#ifndef ZGADULA_H
#define ZGADULA_H

#include <QMainWindow>

#include "Menu.h"
#include "GameSetup.h"
#include "Game.h"
#include "GameFinish.h"
#include "Scores.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Zgadula; }
QT_END_NAMESPACE

class Zgadula : public QMainWindow
{
    Q_OBJECT

public:
    Zgadula(QWidget *parent = nullptr);
    ~Zgadula();

private:
    Ui::Zgadula *ui;

    Menu *m;
    GameSetup *gs;
    Game *g;
    GameFinish *gf;
    Scores *s;

private slots:
    void showSetup();
    void showScores();
    void returnToMenu();
    void setupGame();
    void finishGame();
    void exitApp();
};
#endif // ZGADULA_H
