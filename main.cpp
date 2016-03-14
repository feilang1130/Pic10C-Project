/*
 * Pic 10C
 * Teng Xu
 * Final project
 * Whac-A-Mole game
 * I implement all the logic but still have bug that I cannot fix
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
