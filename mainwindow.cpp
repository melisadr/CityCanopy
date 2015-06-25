#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include "exporterwrf.h"
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
       QMainWindow(parent),
       ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openTopoButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (fileName != ""){
        qDebug() << "Opening :" << fileName;
        TopoFigure figure;
        topoDataManager.load(fileName);
        figure.load(topoDataManager);
        ui->openGLWidget->initFigure(figure);
    }
}

void MainWindow::on_openUrbanButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName != ""){
        qDebug() << "Opening :" << fileName;
        UrbanFigure figure;
        urbanDataManager.load(fileName);
        figure.load(urbanDataManager);
        ui->openGLWidget->initFigure(figure);
    }
}

void MainWindow::on_exportButton_clicked()
{
    ExporterWRF exporterWRF;
    exporterWRF.exportData(urbanDataManager);
}
