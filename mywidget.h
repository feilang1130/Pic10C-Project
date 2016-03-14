#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVector>
#include <QTimer>

class myWidget : public QWidget
{
    Q_OBJECT

    static QVector<myWidget*> all;  //Stores all widgets
public:
    myWidget(QLabel* the_mouse, QLabel* the_mouse_appear, QWidget* the_mouse_clicked);
    myWidget();
    void appear_show();

signals:
    void get_point();
public slots:

    void not_appear();
protected:
    virtual void mousePressEvent(QMouseEvent *event);

private:
    QHBoxLayout *horiz;
    QHBoxLayout *horiz1;
    QHBoxLayout *horiz2;
    QHBoxLayout *horiz3;
    QWidget* mouse;
    QWidget* mouse_appear;
    QWidget* mouse_clicked;
    bool stop;
};

#endif // MYWIDGET_H
