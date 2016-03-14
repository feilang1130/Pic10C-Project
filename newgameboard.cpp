#include "newgameboard.h"
#include "ui_newgameboard.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <QImage>
#include <QVector>
#include <ctime>
#include <qglobal.h>
#include <QTime>


int NewGameBoard::randInt(int low,int high)
{
    return qrand() % ((high + 1) - low) + low;
}

NewGameBoard::NewGameBoard(QWidget *parent , size_t board_size) :
    QWidget(parent),ui(new Ui::newGameBoard), size(board_size),
    ui(new Ui::NewGameBoard)
{

    ui->setupUi(this);                                                             //set up the layout and widget
    QTime T = QTime::currentTime();
    qsrand((uint)T.msec());
    srand(time(0));
    qsrand(qrand());
    this->setFixedSize(size*80,sizeh*80);
    QVBoxLayout *v_layout= new  QVBoxLayout;
    QWidget* topWidget= new QWidget;
    QWidget* timeWidget = new QWidget;
    QWidget* bottomWidget= new QWidget;
    QWidget* boosters = new QWidget;
    QWidget* bottomWidget_align= new QWidget;
    QHBoxLayout *horiz=new QHBoxLayout(topWidget);
    QGridLayout *layout = new QGridLayout(bottomWidget);
    QHBoxLayout *timelayout = new QHBoxLayout(timeWidget);
    QVBoxLayout *boosters_layout= new  QVBoxLayout(boosters);
    QHBoxLayout *layout_align = new QHBoxLayout(bottomWidget_align);
    boosters->setFixedWidth(80);
    bottomWidget->setFixedHeight(sizeh*80);
    bottomWidget->setFixedWidth(size*80);
    layout->setSpacing(0);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    QLabel *title= new QLabel("Whac-A-Mole");

    mylabel *time = new mylabel(120);                                                   //set up the time label
    time->setFixedWidth(140);
    title->setAlignment(Qt::AlignCenter);
    horiz->addWidget(title,0,Qt::AlignRight);
    horiz->addWidget(time,0,Qt::AlignRight);
    QTimer* timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),time,SLOT(showTime()));
    timer->start(1000);
    connect(time,SIGNAL(noTime()),this,SLOT(GameOver()));
    connect(time,SIGNAL(noTime()),timer,SLOT(stop()));
    mylabel *addtime = new mylabel(30);
    addtime->setAlignment(Qt::AlignRight);
    timelayout->addWidget(addtime);
    timeWidget->setFixedHeight(10);

    QLabel *action=new QLabel("Actions:");
    boosters_layout->addWidget(action,0,Qt::AlignCenter);
    QPushButton *restart= new QPushButton("Restart");
    boosters_layout->addWidget(restart,0,Qt::AlignCenter);
    QPushButton *pause= new QPushButton("Pause");
    boosters_layout->addWidget(pause,0,Qt::AlignCenter);
    QPushButton *resume= new QPushButton("Resume");
    boosters_layout->addWidget(resume,0,Qt::AlignCenter);
    QPushButton *back= new QPushButton("Back");
    boosters_layout->addWidget(back,0,Qt::AlignCenter);
    connect(pause,SIGNAL(clicked(bool)),timer,SLOT(stop()));
    connect(resume,SIGNAL(clicked(bool)),timer,SLOT(start()));
    connect(back,SIGNAL(clicked(bool)),parent,SLOT(game_over()));
    QPushButton *moretime= new QPushButton("time");
    boosters_layout->addWidget(moretime,0,Qt::AlignCenter);
    connect(moretime,SIGNAL(clicked(bool)),addtime,SLOT(show_add_time()));
    connect(moretime,SIGNAL(clicked(bool)),time,SLOT(add_time()));


    QLabel **label = new QLabel*[3*size*size];                               //store all the label
    myWidget **widgets = new myWidget*[size*size];                           //store all mywidget
    Qpixmap Mouse_Appear(":/dishu1.png");
    Qpixmap Mouse_Clicked(":/dishu2.jpg");
    Qpicmap Mouse(":/dishu3.jpg");



    for(size_t i=0;i<(size*size);i++)                                        //set the picture to all the widget
    {
        label[i] = new QLabel;
        label[i+size*size] = new QLabel;
        label[i+2*size*size] = new QLabel;
        label[i]->setPixmap(Mouse);
        label[i+size*size]->setPixmap(Mouse_Appear);
        label[i+2*size*size]->setPixmap(Mouse_Clicked);
        widgets[i]=new myWigdet(label[i],label[i+size*size],label[i+2*size*size],size*size);
        layout->addWidget(widgets[i],i/size,i%size);

    }
    while(!time.check_no_time())                                           //a mouse will appear per sec randomly
    {
        QTimer* timer1=new QTimer(this);
        size_t index=randInt(0,size*size);
        widgets[index]->appear_show();
        timer1->start(1000);
        connect(timer1,SIGNAL(timeout()),widgets[index],SLOT(not_appear()));
    }
    layout_align->addWidget(bottomWidget,0,Qt::AlignLeft);
    layout_align->addWidget(boosters,0,Qt::AlignRight);
    v_layout->addWidget(topWidget);
    v_layout->addWidget(timeWidget);
    v_layout->addWidget(bottomWidget_align);
    this->setLayout(v_layout);

}


void newGameBoard::GameOver()
{
    QWidget* gameOver = new QWidget();
    gameOver->setFixedWidth(400);
    QVBoxLayout* gmov=new QVBoxLayout();
    QLabel *title = new QLabel("Game Over!");
    title->setAlignment(Qt::AlignCenter);
    QFont title_font = title->font();
    title_font.setPointSize(20);
    title->setFont(title_font);
    gmov->addSpacing(30);
    gmov->addWidget(title);
    gmov->addSpacing(15);
    QLabel* content = new QLabel();
    QString txt = "Do you want to try it again?";
    content->setText(txt);
    content->setAlignment(Qt::AlignCenter);
    gmov->addWidget(content);
    gmov->addSpacing(20);
    QPushButton* yes = new QPushButton("Yes");
    QPushButton* no = new QPushButton("No");
    yes->setFixedWidth(50);
    no->setFixedWidth(50);
    QHBoxLayout* yorn = new QHBoxLayout();
    yorn->addWidget(yes);
    yorn->addWidget(no);

    connect(yes,SIGNAL(clicked(bool)),parent(),SLOT(game_begin()));
    connect(yes,SIGNAL(clicked(bool)),gameOver,SLOT(close()));
    connect(no,SIGNAL(clicked(bool)),parent(),SLOT(game_over()));
    connect(no,SIGNAL(clicked(bool)),gameOver,SLOT(close()));
    gmov->addLayout(yorn);
    gmov->addSpacing(30);
    gameOver->setLayout(gmov);
    gameOver->show();
}

mylabel::mylabel(int a)
{
    sec=a;
}

int mylabel::gettime()
{
    return sec;
}

bool mylabel::check_no_time()
{
    if(sec==0)
        return 1;
    else
        return 0;

}

void mylabel::showTime()
{
    int min=sec/60;
    QString mintext=QString::number(min);
    QString sectext;
    if(sec%60==0)
        sectext="00";
    else if(sec%60>9)
        sectext=QString::number(sec%60);
    else
        sectext="0"+QString::number(sec%60);
    this->setText("Time Remaining: "+mintext+":"+sectext);
    if (sec>0)
        sec--;
    else if (sec==0)
        emit noTime();
}

void mylabel::add_time()
{
    sec+=30;
}

NewGameBoard::~NewGameBoard()
{
    delete ui;
}
