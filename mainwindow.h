#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "stats.h"

struct TInterfaceMessage
{
    QString DoubleData;
    QString ChrData;
};



namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void send(TInterfaceMessage);

private slots:
    void sendEvent();
    void stopEvent();
    void startEvent();

public slots:
    void showStats();
    void recieve(TInterfaceMessage);

private:
    Ui::MainWindow *ui;
    Stats *stats;
    QTimer *timer;
    QTime *time;
};

#endif // MAINWINDOW_H

