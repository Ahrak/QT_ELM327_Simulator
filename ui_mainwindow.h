/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClearConsole;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *portWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSerialConnect;
    QPushButton *btnSerialDisconnect;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *displayRPM;
    QLabel *label_7;
    QLineEdit *displaySpeed;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *displayThrottle;
    QLineEdit *displayTemp;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QLineEdit *editUDP_Port;
    QLabel *label_3;
    QLineEdit *editUDP_IP;
    QLabel *label_2;
    QPushButton *btnUDP;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *terminal;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *editCmd;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuAnsicht;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(641, 466);
        actionClearConsole = new QAction(MainWindow);
        actionClearConsole->setObjectName(QStringLiteral("actionClearConsole"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(9);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 3, 6, 3);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        portWidget = new QTableWidget(groupBox);
        if (portWidget->columnCount() < 3)
            portWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        portWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        portWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        portWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        portWidget->setObjectName(QStringLiteral("portWidget"));

        verticalLayout_2->addWidget(portWidget);

        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSerialConnect = new QPushButton(widget_3);
        btnSerialConnect->setObjectName(QStringLiteral("btnSerialConnect"));

        horizontalLayout_2->addWidget(btnSerialConnect);

        btnSerialDisconnect = new QPushButton(widget_3);
        btnSerialDisconnect->setObjectName(QStringLiteral("btnSerialDisconnect"));

        horizontalLayout_2->addWidget(btnSerialDisconnect);


        verticalLayout_2->addWidget(widget_3);

        portWidget->raise();
        portWidget->raise();
        widget_3->raise();

        horizontalLayout->addWidget(groupBox);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 0);
        widget_5 = new QWidget(groupBox_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(35, 0));
        label_5->setMaximumSize(QSize(50, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        displayRPM = new QLineEdit(widget_5);
        displayRPM->setObjectName(QStringLiteral("displayRPM"));
        displayRPM->setReadOnly(true);

        gridLayout_3->addWidget(displayRPM, 2, 1, 1, 1);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 2);

        displaySpeed = new QLineEdit(widget_5);
        displaySpeed->setObjectName(QStringLiteral("displaySpeed"));
        displaySpeed->setReadOnly(true);

        gridLayout_3->addWidget(displaySpeed, 1, 1, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(35, 0));
        label_4->setMaximumSize(QSize(50, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_8 = new QLabel(widget_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 3, 0, 1, 1);

        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 4, 0, 1, 1);

        displayThrottle = new QLineEdit(widget_5);
        displayThrottle->setObjectName(QStringLiteral("displayThrottle"));
        displayThrottle->setReadOnly(true);

        gridLayout_3->addWidget(displayThrottle, 3, 1, 1, 1);

        displayTemp = new QLineEdit(widget_5);
        displayTemp->setObjectName(QStringLiteral("displayTemp"));
        displayTemp->setReadOnly(true);

        gridLayout_3->addWidget(displayTemp, 4, 1, 1, 1);


        verticalLayout_3->addWidget(widget_5);

        widget_4 = new QWidget(groupBox_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        editUDP_Port = new QLineEdit(widget_4);
        editUDP_Port->setObjectName(QStringLiteral("editUDP_Port"));

        gridLayout_2->addWidget(editUDP_Port, 2, 1, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(35, 0));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        editUDP_IP = new QLineEdit(widget_4);
        editUDP_IP->setObjectName(QStringLiteral("editUDP_IP"));

        gridLayout_2->addWidget(editUDP_IP, 1, 1, 1, 1);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(35, 0));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        btnUDP = new QPushButton(widget_4);
        btnUDP->setObjectName(QStringLiteral("btnUDP"));

        gridLayout_2->addWidget(btnUDP, 3, 0, 1, 2);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 2);


        verticalLayout_3->addWidget(widget_4);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        terminal = new QTextEdit(groupBox_2);
        terminal->setObjectName(QStringLiteral("terminal"));
        terminal->setStyleSheet(QStringLiteral("background-color:black; color: white;"));
        terminal->setReadOnly(true);

        verticalLayout->addWidget(terminal);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QFont font1;
        font1.setPointSize(10);
        widget_2->setFont(font1);
        widget_2->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"	border: 1px solid white;\n"
"}\n"
"\n"
"QLabel, QLineEdit\n"
"{\n"
"	background-color: black; border: none; color:white;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 0, 1, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(11);
        label->setFont(font2);

        horizontalLayout_3->addWidget(label);

        editCmd = new QLineEdit(widget_2);
        editCmd->setObjectName(QStringLiteral("editCmd"));
        editCmd->setFont(font2);

        horizontalLayout_3->addWidget(editCmd);


        verticalLayout->addWidget(widget_2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 21));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menuAnsicht = new QMenu(menuBar);
        menuAnsicht->setObjectName(QStringLiteral("menuAnsicht"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuAnsicht->menuAction());
        menuAnsicht->addAction(actionClearConsole);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ELM327_Simulator", 0));
        actionClearConsole->setText(QApplication::translate("MainWindow", "Konsole l\303\266schen", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial Port", 0));
        QTableWidgetItem *___qtablewidgetitem = portWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = portWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Beschreibung", 0));
        QTableWidgetItem *___qtablewidgetitem2 = portWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Hersteller", 0));
        btnSerialConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        btnSerialDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "UDP", 0));
        label_5->setText(QApplication::translate("MainWindow", "RPM", 0));
        label_7->setText(QApplication::translate("MainWindow", "Daten", 0));
        label_4->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_8->setText(QApplication::translate("MainWindow", "Throttle", 0));
        label_9->setText(QApplication::translate("MainWindow", "Temp", 0));
        editUDP_Port->setText(QApplication::translate("MainWindow", "9662", 0));
        label_3->setText(QApplication::translate("MainWindow", "Port", 0));
        editUDP_IP->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("MainWindow", "IP", 0));
        btnUDP->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_6->setText(QApplication::translate("MainWindow", "Verbindung", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "OBD2 Console", 0));
        terminal->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", " > ", 0));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0));
        menuAnsicht->setTitle(QApplication::translate("MainWindow", "Ansicht", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
