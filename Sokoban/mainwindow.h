#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtGui>

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
    QGraphicsRectItem *rectangle;
    wall border;

private:
    bool collided(QGraphicsItem *item1, QGraphicsItem *item2)
    {
        if(item1->collidesWithItem(item2))
        {
            return true;
        }
        else return false;
    }

protected:
    void keyPressEvent(QKeyEvent *k);
};

#endif // MAINWINDOW_H
