#include "Menu.h"
#include "ui_Menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_btnPlay_clicked()
{
    emit showSetup();
}

void Menu::on_btnScores_clicked()
{
    emit showScores();
}

void Menu::on_btnExit_clicked()
{
    emit exitApp();
}
