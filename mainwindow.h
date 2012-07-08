#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>

#include <QPen>
#include <QBrush>
#include <QColor>

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

private:
    enum keys {
        key_left=65361,
        key_up=65362,
        key_right=65363,
        key_down=65364,
        key_enter=65293,
        key_esc=65307
    };
    typedef struct _wall {
        QGraphicsLineItem *top;
        QGraphicsLineItem *bottom;
        QGraphicsLineItem *left;
        QGraphicsLineItem *right;
    } wall;

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    Block *player;
    wall border;
    Map *m;

    QPen blackpen;
    QBrush boxbrush;
    QBrush brickbrush;
    QBrush spotbrush;
    QBrush floorbrush;
    QBrush gamerbrush;

private:
    void drawMap();
    void drawSpots();
    void drawBoxes();
    void drawGamer();
    bool canWalk(int direction, Block* block);
    bool boxMove(int direction, Block* box);
    Block * getPlayer();

protected:
    void keyPressEvent(QKeyEvent *k);
};

#endif // MAINWINDOW_H
