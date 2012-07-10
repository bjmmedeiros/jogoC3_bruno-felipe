#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include <QtCore>
#include <QtGui>

#include <QPen>
#include <QBrush>
#include <QColor>
#include <QDir>
#include <QStringList>

#include "map.h"
#include "block.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionNew_Game_triggered();
    void on_actionTest_triggered();
    void updateGamer(int direction);
    void updateBoxes();
    void boxOnSpot(QPoint pos);
    void updateHUD();
    void removeGamerWarning();
    void on_actionMap_Editor_triggered();
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_floorButton_clicked();
    void on_brickButton_clicked();
    void on_boxButton_clicked();
    void on_spotButton_clicked();
    void on_gamerButton_clicked();
    void on_okButton_clicked();
    void finishGame();

signals:
    void gamerUpdated(int direction);
    void boxUpdated();
    void onSpot(QPoint pos);
    void nextLevel();
    void hudUpdated();
    void gamerRemoved();
    void gameOver();

private:
    enum keys {
        key_left=65361,
        key_up=65362,
        key_right=65363,
        key_down=65364,
        key_enter=65293,
        key_esc=65307,
        key_backspace=65288
    };
    typedef struct _wall {
        QGraphicsLineItem *top;
        QGraphicsLineItem *bottom;
        QGraphicsLineItem *left;
        QGraphicsLineItem *right;
    } wall;

    typedef struct _buttonSet {
        int button;
        bool isSet;
    } buttonSet;

    enum buttons
    {
        setFloor=0,
        setBrick=1,
        setBox=2,
        setSpot=3,
        setGamer=4
    };

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    wall border;
    Map *m;

    QPen blackpen;

    QBrush floorbrush;
    QBrush brickbrush;
    QBrush boxbrush;
    QBrush spotbrush;
    QBrush boxspotbrush;
    QBrush gamerbrush;

    QDir *folder;
    QStringList mapList;
    int currentLevel;
    int moves;
    int pushes;

    buttonSet bs;


private:
    void drawMap();
    void drawSpots();
    void drawBoxes();
    void drawGamer();
    bool canWalk(int direction, Block* block);
    bool canMoveBox(int direction, Box *current);
    bool allBoxesOnSpot();

    bool isGamer(QPoint point);
    bool isBox(QPoint point);
    bool isSpot(QPoint point);

protected:
    void keyPressEvent(QKeyEvent *k);
    void mousePressEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
