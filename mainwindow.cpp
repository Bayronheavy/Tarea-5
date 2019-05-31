#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include <QTimer>
#include <QGraphicsItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escen = new QGraphicsScene();  //Reservando memoria para un puntero a un objeto escena de Qt

    ui->escena->setScene(escen);  //Montando la escena en el widget GraphicsView


    escen->setSceneRect(-250,-250,250,250);


  particula = new Particula(-250,-250,5,5,15);  //Declarando un objeto grafico de la clase Particula

  escen->addItem(particula); //Agregando el objeto grafico a la escena

    timer = new QTimer(this);
    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEscena(void)
{
    particula->moverParticula(dt, vertlim);
    particula->colisionParticula(horzlim, vertlim);
}


void MainWindow::on_star_clicked()
{
    timer->start(50);
}
