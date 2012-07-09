/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jul 9 00:29:00 2012
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
#include <QtGui/QFrame>
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
    QAction *actionTest;
    QWidget *centralWidget;
    QLabel *gameName;
    QGraphicsView *scenario;
    QFrame *gameHUD;
    QLabel *label_level;
    QLabel *label_currentLevel;
    QLabel *label_moves;
    QLabel *label_pushes;
    QLabel *label_of;
    QLabel *label_maxLevel;
    QLabel *pushes;
    QLabel *moves;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuPlay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(760, 655);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionMap_Editor = new QAction(MainWindow);
        actionMap_Editor->setObjectName(QString::fromUtf8("actionMap_Editor"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QString::fromUtf8("actionTest"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gameName = new QLabel(centralWidget);
        gameName->setObjectName(QString::fromUtf8("gameName"));
        gameName->setGeometry(QRect(10, 10, 600, 600));
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
        gameHUD = new QFrame(centralWidget);
        gameHUD->setObjectName(QString::fromUtf8("gameHUD"));
        gameHUD->setGeometry(QRect(630, 50, 120, 160));
        gameHUD->setFrameShape(QFrame::NoFrame);
        gameHUD->setFrameShadow(QFrame::Raised);
        label_level = new QLabel(gameHUD);
        label_level->setObjectName(QString::fromUtf8("label_level"));
        label_level->setGeometry(QRect(13, 14, 38, 23));
        label_currentLevel = new QLabel(gameHUD);
        label_currentLevel->setObjectName(QString::fromUtf8("label_currentLevel"));
        label_currentLevel->setGeometry(QRect(57, 14, 16, 23));
        label_moves = new QLabel(gameHUD);
        label_moves->setObjectName(QString::fromUtf8("label_moves"));
        label_moves->setGeometry(QRect(13, 59, 47, 23));
        label_pushes = new QLabel(gameHUD);
        label_pushes->setObjectName(QString::fromUtf8("label_pushes"));
        label_pushes->setGeometry(QRect(13, 104, 49, 23));
        label_of = new QLabel(gameHUD);
        label_of->setObjectName(QString::fromUtf8("label_of"));
        label_of->setGeometry(QRect(70, 10, 16, 31));
        label_maxLevel = new QLabel(gameHUD);
        label_maxLevel->setObjectName(QString::fromUtf8("label_maxLevel"));
        label_maxLevel->setGeometry(QRect(90, 10, 16, 31));
        pushes = new QLabel(gameHUD);
        pushes->setObjectName(QString::fromUtf8("pushes"));
        pushes->setGeometry(QRect(73, 104, 16, 23));
        moves = new QLabel(gameHUD);
        moves->setObjectName(QString::fromUtf8("moves"));
        moves->setGeometry(QRect(73, 59, 16, 23));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(610, 0, 20, 621));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 31));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuPlay->menuAction());
        menuPlay->addAction(actionNew_Game);
        menuPlay->addAction(actionMap_Editor);
        menuPlay->addAction(actionTest);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        actionMap_Editor->setText(QApplication::translate("MainWindow", "Map Editor", 0, QApplication::UnicodeUTF8));
        actionTest->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
        gameName->setText(QApplication::translate("MainWindow", "Sokoban", 0, QApplication::UnicodeUTF8));
        label_level->setText(QApplication::translate("MainWindow", "Level:", 0, QApplication::UnicodeUTF8));
        label_currentLevel->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_moves->setText(QApplication::translate("MainWindow", "Moves:", 0, QApplication::UnicodeUTF8));
        label_pushes->setText(QApplication::translate("MainWindow", "Pushes:", 0, QApplication::UnicodeUTF8));
        label_of->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        label_maxLevel->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushes->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        moves->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        menuPlay->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
