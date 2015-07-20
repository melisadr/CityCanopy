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
        topoDataManager = new TopoDataManager;
        topoDataManager->load(fileName);
        ui->openGLWidget->initFigure(topoDataManager);
    }
}

void MainWindow::on_openUrbanButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName != ""){
        qDebug() << "Opening :" << fileName;
        QSharedPointer<Figure> figure = QSharedPointer<Figure>(new UrbanFigure);
        urbanDataManager = new UrbanDataManager;
        urbanDataManager->load(fileName);
        ui->openGLWidget->initFigure(urbanDataManager);
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
