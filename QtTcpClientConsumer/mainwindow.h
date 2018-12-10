#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

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
  void getData();

  void stopdata();

  QString getIP();

  void ListHosts();

  void tcpConnect();

  void tcpDisconnect();

  void timerEvent(QTimerEvent *event);

private:
  int timer_id;
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
