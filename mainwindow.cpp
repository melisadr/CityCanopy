#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include "topodatamanager.h"
#include "topofigure.h"
#include "urbandatamanager.h"
#include "urbanfigure.h"
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
        TopoDataManager dataManager;
        dataManager.load(fileName);
        figure.load(dataManager);
        ui->openGLWidget->initFigure(figure);
    }
}

void MainWindow::on_openUrbanButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName != ""){
        qDebug() << "Opening :" << fileName;
        UrbanFigure figure;
        UrbanDataManager dataManager;
        dataManager.load(fileName);
        figure.load(dataManager);
        ui->openGLWidget->initFigure(figure);
    }
}
