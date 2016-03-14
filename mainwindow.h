#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void game_begin();

private slots:
     void displayInstruction();
     void on_quit_clicked();


private:
    Ui::MainWindow *ui;
    newGameBoard* board;
};

#endif // MAINWINDOW_H
