#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "particula.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int dt=3;
    int horzlim = 250;
    int vertlim = 250;



private slots:
    void on_star_clicked();
    void actualizarEscena();

private:
    Ui::MainWindow *ui;
    Particula *particula;
    QTimer *timer;
     QGraphicsScene *escen;


};

#endif // MAINWINDOW_H
