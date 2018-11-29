#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

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
    void putData();
    void stopData();
    QString getIP();
    void tcpConnect();
    void tcpDisconnect();
    void timerEvent(QTimerEvent *event);

private:
    int timerID;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};


#endif // MAINWINDOW_H
