#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game_begin()                                                       //set up for a game begin
{
     this->setFixedSize(4*80+135,3*80+130);
     board = new newGameBoard(this,6);
     this->setCentralWidget(board);
}


void MainWindow::displayInstruction()                                                //show the instruction
{
    QWidget* instruction = new QWidget();
    QVBoxLayout* instru=new QVBoxLayout();
    QLabel *title = new QLabel("Instruction");
    title->setAlignment(Qt::AlignCenter);
    QFont title_font = title->font();
    title_font.setPointSize(25);
    title->setFont(title_font);
    instru->addSpacing(50);
    instru->addWidget(title);
    instru->addSpacing(25);
    QLabel* content = new QLabel();
    QString text = "      There are 36 mouse holes and mouse will appear randomly per sec "
                      "\n\nTry to hit them to get point\n";
    content->setText(text);
    instru->addWidget(content);
    instru->addSpacing(50);
    instruction->setLayout(instr);
    instruction->show();



}

void MainWindow::on_quit_clicked()                                                  //quit the game
{
    this->close();
}


