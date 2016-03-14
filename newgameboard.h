#ifndef NEWGAMEBOARD_H
#define NEWGAMEBOARD_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPixmap>
#include<QString>
#include <iostream>
#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include "mywidget.h"
#include <QWidget>
#include <QGlobal.h>
#include <QTime>
namespace Ui {
class newGameBoard;
class mylabel;
}

class newGameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit newGameBoard(QWidget *parent = 0, size_t size=6);
    ~newGameBoard();
    int randInt(int low,int high);

public slots:
    void GameOver();

private:
    Ui::newGameBoard *ui;
    QWidget *Board;
    size_t size;
};

class mylabel : public QLabel
{
    Q_OBJECT
public:
    mylabel(int a);
    int gettime();
    bool check_no_time();

public slots:
    void add_time();
    void show_add_time();
    void showTime();
signals:
    void noTime();
private:
    int sec;
};



#endif // NEWGAMEBOARD_H
