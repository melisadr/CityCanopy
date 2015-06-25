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
       ui(new Ui::MainWindow),
       urban_set(0),
       topo_set(0)
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
        topo_set = 1;
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
        urban_set = 1;
        figure.load(urbanDataManager);
        ui->openGLWidget->initFigure(figure);
    }
}

void MainWindow::on_exportButton_clicked()
{
    if( urban_set > 0){
        QString pathToExport = QFileDialog::getExistingDirectory();
        if(pathToExport != "" ){
            QDir::setCurrent(pathToExport);
            ExporterWRF exporterWRF;
            exporterWRF.exportData(urbanDataManager);
        }
    }else{
        QMessageBox::information(this,tr("Error exporting"),tr("No urban data loaded"));
    }
}
