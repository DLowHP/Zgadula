#ifndef GAMEFINISH_H
#define GAMEFINISH_H

#include <QWidget>

namespace Ui {
class GameFinish;
}

class GameFinish : public QWidget
{
    Q_OBJECT

public:
    explicit GameFinish(QWidget *parent = nullptr);
    ~GameFinish();

    void setMsg(QString msg);
    void setGuessedNumber(int value);
    void setGuessedIn(int value);

private slots:
    void on_btnContinue_clicked();

    void on_btnFinish_clicked();

private:
    Ui::GameFinish *ui;

signals:
    void returnToMenu();
    void exitApp();
};

#endif // GAMEFINISH_H
