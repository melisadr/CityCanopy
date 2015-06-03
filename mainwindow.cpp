#include "mainwindow.h"
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


MainWindow::MainWindow() : centralWidget(0)
{
    initMenuBar();
    initCentralWidget();
    initToolBar();
}

void MainWindow::initMenuBar()
{
    QMenuBar *menuBar = new QMenuBar;
    setMenuBar(menuBar);

    QMenu *menuArchive = menuBar->addMenu(tr("Archive"));

    QAction *openTopo = new QAction(menuArchive);
    openTopo->setText(tr("Open topo"));
    menuArchive-> addAction(openTopo);
    connect(openTopo,SIGNAL(triggered()),this,SLOT(openTopo()));

    QAction *openUrban = new QAction(menuArchive);
    openUrban->setText(tr("Open urban"));
    menuArchive-> addAction(openUrban);
    connect(openUrban,SIGNAL(triggered()),this,SLOT(openUrban()));

}

void MainWindow::initCentralWidget()
{
    if (!centralWidget)
    {
        centralWidget = new GLWidget(this);
        setCentralWidget(centralWidget);
    }

}

void MainWindow::initToolBar()
{
    QToolBar *toolBar = new QToolBar(tr("&Tools"));
    QAction *clearWidget = new QAction(toolBar);
    clearWidget->setText(tr("Clear"));
    toolBar->addAction(clearWidget);

    addToolBar(Qt::RightToolBarArea, toolBar);

}

void MainWindow::openTopo()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << "Opening :" << fileName;
    TopoFigure figure;
    TopoDataManager dataManager;
    dataManager.load(fileName);
    figure.load(dataManager);
    centralWidget->initFigure(figure);
}

void MainWindow::openUrban()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << "Opening :" << fileName;
    UrbanFigure figure;
    UrbanDataManager dataManager;
    dataManager.load(fileName);
    figure.load(dataManager);
    centralWidget->initFigure(figure);

}
