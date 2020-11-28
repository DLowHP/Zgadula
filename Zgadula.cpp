#include "Zgadula.h"
#include "ui_Zgadula.h"

#include "Menu.h"
#include "GameSetup.h"
#include "Game.h"
#include "GameFinish.h"
#include "Scores.h"

Zgadula::Zgadula(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zgadula)
{
    ui->setupUi(this);

    m = new Menu;
    gs = new GameSetup;
    g = new Game;
    gf = new GameFinish;
    s = new Scores;

    ui->container->insertWidget(0, m);
    ui->container->insertWidget(1, gs);
    ui->container->insertWidget(2, g);
    ui->container->insertWidget(3, gf);
    ui->container->insertWidget(4, s);

    ui->container->setCurrentIndex(0);

    connect(m, SIGNAL(showSetup()), this, SLOT(showSetup()));
    connect(m, SIGNAL(showScores()), this, SLOT(showScores()));
    connect(m, SIGNAL(exitApp()), this, SLOT(exitApp()));

    connect(gs, SIGNAL(returnToMenu()), this, SLOT(returnToMenu()));
    connect(gs, SIGNAL(setupGame()), this, SLOT(setupGame()));

    connect(g, SIGNAL(gameFinished()), this, SLOT(finishGame()));

    connect(gf, SIGNAL(returnToMenu()), this, SLOT(returnToMenu()));
    connect(gf, SIGNAL(exitApp()), this, SLOT(exitApp()));

    connect(s, SIGNAL(returnToMenu()), this, SLOT(returnToMenu()));
}

Zgadula::~Zgadula()
{
    delete ui;
}

void Zgadula::showSetup()
{
    ui->container->setCurrentIndex(1);
}

void Zgadula::showScores()
{
    ui->container->setCurrentIndex(4);
}

void Zgadula::returnToMenu()
{
    ui->container->setCurrentIndex(0);
}

void Zgadula::setupGame()
{
    ui->container->setCurrentIndex(2);
    g->setValues(gs->getPlayerName(), gs->getRangeMin(), gs->getRangeMax());
    g->setupGame();
}

void Zgadula::finishGame()
{
    ui->container->setCurrentIndex(3);
    if (g->getGameState()) {
        gf->setMsg(QString("Udalo Ci sie zgadnac liczbe, brawo!"));
        s->appendScore(gs->getPlayerName(), g->getGuessedNumber(), g->getGuessedIn());
    } else {
        gf->setMsg(QString("Niestety, nie udalo sie..."));
    }
    gf->setGuessedNumber(g->getGuessedNumber());
    gf->setGuessedIn(g->getGuessedIn());
}

void Zgadula::exitApp()
{
    this->close();
}


