#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonConectar,SIGNAL(clicked(bool)),this,SLOT(tcpConnect()));
  connect(ui->pushButtonDesconectar,SIGNAL(clicked(bool)),this,SLOT(tcpDisconnect()));
  connect(ui->pushButtonPut,SIGNAL(clicked(bool)),this,SLOT(putData()));
  connect(ui->pushButtonParar,SIGNAL(clicked(bool)),this,SLOT(stopData()));
}
QString MainWindow::getIP(){
    /*! @brief Recupera o IP digitado na caixa no campo do mesmo.
     * */
    QString ip;
    /*! @param ip armazena o IP recuperado no campo de inserção do IP.
     * */
    ip = ui->lineEdit->text();
    qDebug() << ip;
    return ip;
}

void MainWindow::tcpConnect(){

  socket->connectToHost(getIP(),1234);
  /*! connectToHost(getIP(),1234) Chama a função getIP para pegar o valor digitado no espaço gráfico.
   * É acionado quando o botão conectar é pressionado.
   */
  if(socket->waitForConnected(3000)){
      /*! waitForConnected(3000) Verifica se a conexão está estabelecida
       * */
        qDebug() << "Conectado";
        ui->labelVerifica->setText("Conectado ao servidor");
  } else {
        qDebug() << "Desconectado";
        ui->labelVerifica->setText("Desconectado");
  }
}

void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
    /*! @brief Finaliza a conexão com o servidor.
     * É acionado quando o botão desconectar é pressionado.
     * */
    qDebug() << "Desconectado";
    ui->labelVerifica->setText("Desconectado");
}

void MainWindow::putData(){
    int tempo;
    /*! @param tempo Armazena o intervalo de recebimento entre um dado e o outro selecionado no slider.
     * */
    tempo = ui->lcdNumber->value();
    qDebug()<<tempo;
    timerID= startTimer(tempo*600);

}

void MainWindow::stopData(){
    killTimer(timerID);
    /*! @brief Finaliza a transmissão de dados.
     * */
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    int min,max;
    /*! @param min recebe o valor mostrado ao lado do slider do valor mínimo.
     * @param max recebe o valor mostrado ao lado do slider do valor máximo.
     * @param mensagem exibe uma caixa em forma de pop-up contendo uma mensagem do sistema.
     * @param textomensagem recebe uma mensagem de erro para ser exibida na caixa de diálogo.
     * */
    min = ui->lcdNumberMin->value();
    max = ui->lcdNumberMax->value();
    QString textomensagem;
    QMessageBox mensagem;
    QDateTime datetime;
    QString str;
    qint64 msecdate;
    if((min > max) || ((min == 0) && (max==0))){
        textomensagem = "ERRO! \n O valor de minimo esta maior do \n que o de maximo ou ambos sao zeros";
        mensagem.setText(textomensagem);
        /*! mensagem.setText(textomensagem) Recupera o texto armazenado em textomensagem e manda para a caixa de diálogo.
         * */
        mensagem.exec();
        /*! mensagem.exec() Ativa a caixa de diálogo com um erro do sistema.
         * */
        killTimer(timerID);
    }else{
        if(socket->state()== QAbstractSocket::ConnectedState){

            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
            str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%(max - min) + min)+"\r\n";

            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            if(socket->waitForBytesWritten(3000)){
                qDebug() << "wrote";
            }
            ui->textBrowser->append(str);
        }
    }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
