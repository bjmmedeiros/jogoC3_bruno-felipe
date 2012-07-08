#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

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
    void updateGamer();
    void updateBoxes();
    void boxOnSpot(QPoint pos);

public slots:

signals:
    void gamerUpdated();
    void boxUpdated();
    void onSpot(QPoint pos);

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

    QBrush floorbrush;
    QBrush brickbrush;
    QBrush boxbrush;
    QBrush spotbrush;
    QBrush boxspotbrush;
    QBrush gamerbrush;

private:
    void drawMap();
    void drawSpots();
    void drawBoxes();
    void drawGamer();
    bool canWalk(int direction, Block* block);
    bool canMoveBox(int direction, Box *current);

protected:
    void keyPressEvent(QKeyEvent *k);
};

#endif // MAINWINDOW_H
