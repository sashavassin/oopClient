#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #f1f6fb;");

    this->setWindowTitle("Сборочный цех");
    stats = new Stats();

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->statsButton, SIGNAL(clicked()), this, SLOT(showStats()));
    connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(sendEvent()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopEvent()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startEvent()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::showStats()
{
    stats->setWindowTitle("Статистика");
    stats->show();
}

void MainWindow::sendEvent()
{
    bool valid = true;
    TInterfaceMessage msg;
    msg.DoubleData="";
    if(ui->nLineEdit->text().toInt() <= 0) valid = false;
    msg.DoubleData+= ui->nLineEdit->text()+" ";
    if(ui->mLineEdit->text().toInt() <= 0) valid = false;
    msg.DoubleData+= ui->mLineEdit->text()+" ";
    if(ui->zLineEdit->text().toInt() <= 0) valid = false;
    msg.DoubleData+= ui->zLineEdit->text()+" ";
    if(ui->rLineEdit->text().toInt() <= 0) valid = false;
    msg.DoubleData+= ui->rLineEdit->text();
    msg.ChrData = "d";
    if (valid) emit send(msg);
}



void MainWindow::stopEvent()
{
    TInterfaceMessage msg;
    msg.DoubleData="stop";
    msg.ChrData = "";
    emit send(msg);
}


void MainWindow::startEvent()
{
    TInterfaceMessage msg;
    msg.DoubleData="start";
    msg.ChrData = "";
    emit send(msg);
}


void MainWindow::recieve(TInterfaceMessage msg)
{
    QStringList a = msg.DoubleData.split(" ");
    QFont f( "MS Shell Dlg 2", 12);
    ui->timer->setFont( f);
    ui->timer->setAlignment(Qt::AlignCenter);
    ui->timer->setText(a[0]);

    ui->freeMechs->setFont( f);
    ui->freeMechs->setAlignment(Qt::AlignCenter);
    ui->freeMechs->setText(a[1]);

    ui->busyMechs->setFont( f);
    ui->busyMechs->setAlignment(Qt::AlignCenter);
    ui->busyMechs->setText(a[2]);

    ui->onRepair->setFont( f);
    ui->onRepair->setAlignment(Qt::AlignCenter);
    ui->onRepair->setText(a[3]);

   // ui->brokenMachines->setFont( f);
  //  ui->brokenMachines->setAlignment(Qt::AlignCenter);
  //  ui->brokenMachines->setText(a[4]);

    ui->okayMachines->setFont( f);
    ui->okayMachines->setAlignment(Qt::AlignCenter);
    ui->okayMachines->setText(a[5]);

    if(stats->isVisible())
    {
        stats->setValues(msg.DoubleData);
    }
}
