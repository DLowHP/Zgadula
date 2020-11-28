#ifndef SCORES_H
#define SCORES_H

#include <QWidget>

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

    void appendScore(QString playerName, int guessedNumber, int guessedIn);

private slots:
    void on_btnReturn_clicked();

private:
    Ui::Scores *ui;

signals:
    void returnToMenu();
};

#endif // SCORES_H
