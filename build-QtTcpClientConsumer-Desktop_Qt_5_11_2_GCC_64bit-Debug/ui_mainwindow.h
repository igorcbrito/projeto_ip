/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *labelIP;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QListWidget *listWidget;
    QPushButton *pushButtonUpdate;
    QLabel *labelTiming;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QLabel *labelStatus;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(528, 498);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 10, 241, 421));
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 13, 258, 422));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelIP = new QLabel(widget1);
        labelIP->setObjectName(QStringLiteral("labelIP"));

        verticalLayout->addWidget(labelIP);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonConnect = new QPushButton(widget1);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(widget1);
        pushButtonDisconnect->setObjectName(QStringLiteral("pushButtonDisconnect"));

        horizontalLayout->addWidget(pushButtonDisconnect);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(widget1);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButtonUpdate = new QPushButton(widget1);
        pushButtonUpdate->setObjectName(QStringLiteral("pushButtonUpdate"));

        verticalLayout->addWidget(pushButtonUpdate);

        labelTiming = new QLabel(widget1);
        labelTiming->setObjectName(QStringLiteral("labelTiming"));

        verticalLayout->addWidget(labelTiming);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSlider = new QSlider(widget1);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        lcdNumber = new QLCDNumber(widget1);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_3->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonStart = new QPushButton(widget1);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        horizontalLayout_2->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(widget1);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));

        horizontalLayout_2->addWidget(pushButtonStop);


        verticalLayout->addLayout(horizontalLayout_2);

        labelStatus = new QLabel(widget1);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        verticalLayout->addWidget(labelStatus);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 528, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labelIP->setText(QApplication::translate("MainWindow", "IP", nullptr));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        pushButtonDisconnect->setText(QApplication::translate("MainWindow", "Desconectar", nullptr));
        pushButtonUpdate->setText(QApplication::translate("MainWindow", "Atualizar", nullptr));
        labelTiming->setText(QApplication::translate("MainWindow", "Timing (s):", nullptr));
        pushButtonStart->setText(QApplication::translate("MainWindow", "Iniciar", nullptr));
        pushButtonStop->setText(QApplication::translate("MainWindow", "Parar", nullptr));
        labelStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
