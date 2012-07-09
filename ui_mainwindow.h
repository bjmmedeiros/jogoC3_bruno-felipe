/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jul 9 11:45:01 2012
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
#include <QtGui/QPushButton>
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
    QFrame *editorPanel;
    QPushButton *floorButton;
    QPushButton *brickButton;
    QPushButton *boxButton;
    QPushButton *spotButton;
    QPushButton *gamerButton;
    QLabel *QtSoko;
    QGraphicsView *scenarioEditor;
    QFrame *loadSavePanel;
    QPushButton *loadhButton;
    QPushButton *saveButton;
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
        gameName->setPixmap(QPixmap(QString::fromUtf8("images/qtsoko.png")));
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
        gameHUD->setGeometry(QRect(630, 70, 120, 160));
        gameHUD->setFrameShape(QFrame::Panel);
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
        editorPanel = new QFrame(centralWidget);
        editorPanel->setObjectName(QString::fromUtf8("editorPanel"));
        editorPanel->setGeometry(QRect(630, 250, 120, 271));
        editorPanel->setFrameShape(QFrame::Panel);
        editorPanel->setFrameShadow(QFrame::Raised);
        floorButton = new QPushButton(editorPanel);
        floorButton->setObjectName(QString::fromUtf8("floorButton"));
        floorButton->setGeometry(QRect(10, 20, 91, 33));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/floor.png"), QSize(), QIcon::Normal, QIcon::Off);
        floorButton->setIcon(icon);
        brickButton = new QPushButton(editorPanel);
        brickButton->setObjectName(QString::fromUtf8("brickButton"));
        brickButton->setGeometry(QRect(10, 70, 91, 33));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        brickButton->setIcon(icon1);
        boxButton = new QPushButton(editorPanel);
        boxButton->setObjectName(QString::fromUtf8("boxButton"));
        boxButton->setGeometry(QRect(10, 120, 91, 33));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        boxButton->setIcon(icon2);
        spotButton = new QPushButton(editorPanel);
        spotButton->setObjectName(QString::fromUtf8("spotButton"));
        spotButton->setGeometry(QRect(10, 170, 91, 33));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/spot.png"), QSize(), QIcon::Normal, QIcon::Off);
        spotButton->setIcon(icon3);
        gamerButton = new QPushButton(editorPanel);
        gamerButton->setObjectName(QString::fromUtf8("gamerButton"));
        gamerButton->setGeometry(QRect(10, 220, 91, 33));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/gamerDOWN.png"), QSize(), QIcon::Normal, QIcon::Off);
        gamerButton->setIcon(icon4);
        QtSoko = new QLabel(centralWidget);
        QtSoko->setObjectName(QString::fromUtf8("QtSoko"));
        QtSoko->setGeometry(QRect(630, 10, 121, 41));
        QtSoko->setFrameShape(QFrame::Panel);
        QtSoko->setFrameShadow(QFrame::Raised);
        QtSoko->setTextFormat(Qt::AutoText);
        QtSoko->setAlignment(Qt::AlignCenter);
        scenarioEditor = new QGraphicsView(centralWidget);
        scenarioEditor->setObjectName(QString::fromUtf8("scenarioEditor"));
        scenarioEditor->setGeometry(QRect(10, 10, 600, 600));
        loadSavePanel = new QFrame(centralWidget);
        loadSavePanel->setObjectName(QString::fromUtf8("loadSavePanel"));
        loadSavePanel->setGeometry(QRect(630, 530, 120, 101));
        loadSavePanel->setFrameShape(QFrame::Panel);
        loadSavePanel->setFrameShadow(QFrame::Raised);
        loadhButton = new QPushButton(loadSavePanel);
        loadhButton->setObjectName(QString::fromUtf8("loadhButton"));
        loadhButton->setGeometry(QRect(10, 10, 91, 33));
        saveButton = new QPushButton(loadSavePanel);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(10, 60, 91, 33));
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
        gameName->setText(QString());
        label_level->setText(QApplication::translate("MainWindow", "Level:", 0, QApplication::UnicodeUTF8));
        label_currentLevel->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_moves->setText(QApplication::translate("MainWindow", "Moves:", 0, QApplication::UnicodeUTF8));
        label_pushes->setText(QApplication::translate("MainWindow", "Pushes:", 0, QApplication::UnicodeUTF8));
        label_of->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        label_maxLevel->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushes->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        moves->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        floorButton->setText(QApplication::translate("MainWindow", "Floor", 0, QApplication::UnicodeUTF8));
        brickButton->setText(QApplication::translate("MainWindow", "Brick", 0, QApplication::UnicodeUTF8));
        boxButton->setText(QApplication::translate("MainWindow", "Box", 0, QApplication::UnicodeUTF8));
        spotButton->setText(QApplication::translate("MainWindow", "Spot", 0, QApplication::UnicodeUTF8));
        gamerButton->setText(QApplication::translate("MainWindow", "Player", 0, QApplication::UnicodeUTF8));
        QtSoko->setText(QApplication::translate("MainWindow", "QtSoko", 0, QApplication::UnicodeUTF8));
        loadhButton->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        menuPlay->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
