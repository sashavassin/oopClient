#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) : QDialog(parent), ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #809EEF;");
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

Stats::~Stats()
{
    delete ui;
}

void Stats::setValues(QString DoubleData)
{
    //QFont f( "MS Shell Dlg 2", 14);
    QFont f( "Bell MT", 12);
    ui->Int->setFont( f);
    ui->Int->setAlignment(Qt::AlignCenter);
    ui->Int->setText(DoubleData.split(" ")[6]);
    ui->AvInt->setFont( f);
    ui->AvInt->setAlignment(Qt::AlignCenter);
    ui->AvInt->setText(DoubleData.split(" ")[7]);
    ui->SKO->setFont( f);
    ui->SKO->setAlignment(Qt::AlignCenter);
    ui->SKO->setText(DoubleData.split(" ")[8]);
}
