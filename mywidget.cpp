#include "mywidget.h"
#include<iostream>

myWidget::myWidget(QLabel* the_mouse, QLabel* the_mouse_appear, QWidget* the_mouse_clicked)
{
    mouse=new QWidget;
    mouse_appear=new QWidget;
    mouse_clicked=new QWidget;
    mouse->setFixedWidth(80);
    mouse->setFixedHeight(80);
    mouse_appear->setFixedWidth(80);
    mouse_appear->setFixedHeight(80);
    mouse_clicked->setFixedWidth(80);
    mouse_clicked->setFixedHeight(80);
    horiz1 = new QHBoxLayout(mouse);
    horiz2 = new QHBoxLayout(mouse_appear);
    horiz3 = new QHBoxLayout(mouse_clicked);
    horiz=new QHBoxLayout(this);
    horiz1->addWidget(the_mouse);
    horiz2->addWidget(the_mouse_appear);
    horiz3->addWidget(the_mouse_clicked);
    mouse_appear->hide();
    mouse_clicked->hide();
    horiz->setSpacing(0);
    horiz->setContentsMargins(0,0,0,0);
    horiz->addWidget(mouse);
    horiz->addWidget(mouse_appear);
    horiz->addWidget(mouse_clicked);


}

void myWidget::mousePressEvent(QMouseEvent *event)                                    //when mouse click the hole that has mouse, mouse_clicked will be showned
{
   if(mouse_appear->isVisible())
   {
       mouse_appear->setVisible(false);
       mouse_clicked->setVisible(true);
       emit get_point();
   }
}

void myWidget::appear_show()
{
    mouse->setVisible(false);
    mouse_appear->setVisible(true);
    mouse_clicked->setVisible(false);
 }

void myWidget::not_appear()
{
    mouse->setVisible(ture);
    mouse_appear->setVisible(false);
    mouse_clicked->setVisible(false);
}

myWidget::myWidget()
{

}


