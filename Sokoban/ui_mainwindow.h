/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jul 1 17:15:24 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionMap_Editor;
    QWidget *centralWidget;
    QLabel *gameName;
    QGraphicsView *scenario;
    QMenuBar *menuBar;
    QMenu *menuPlay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(620, 655);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionMap_Editor = new QAction(MainWindow);
        actionMap_Editor->setObjectName(QString::fromUtf8("actionMap_Editor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gameName = new QLabel(centralWidget);
        gameName->setObjectName(QString::fromUtf8("gameName"));
        gameName->setGeometry(QRect(0, 0, 500, 500));
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        gameName->setFont(font);
        gameName->setLayoutDirection(Qt::LeftToRight);
        gameName->setAlignment(Qt::AlignCenter);
        scenario = new QGraphicsView(centralWidget);
        scenario->setObjectName(QString::fromUtf8("scenario"));
        scenario->setGeometry(QRect(10, 10, 600, 600));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scenario->sizePolicy().hasHeightForWidth());
        scenario->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 35));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuPlay->menuAction());
        menuPlay->addAction(actionNew_Game);
        menuPlay->addAction(actionMap_Editor);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        actionMap_Editor->setText(QApplication::translate("MainWindow", "Map Editor", 0, QApplication::UnicodeUTF8));
        gameName->setText(QApplication::translate("MainWindow", "Sokoban", 0, QApplication::UnicodeUTF8));
        menuPlay->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
