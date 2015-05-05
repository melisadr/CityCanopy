#include "mainwindow.h"
#include "glwidget.h"
#include "topodatamanager.h"
#include "topofigure.h"
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

    QMenu *menuArchive = menuBar->addMenu(tr("&Archive"));
    QAction *openFile = new QAction(menuArchive);
    openFile->setText(tr("Open file"));
    menuArchive-> addAction(openFile);
    connect(openFile,SIGNAL(triggered()),this,SLOT(openFile()));
    setMenuBar(menuBar);
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

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << "Opening :" << fileName;
    TopoDataManager topoData;
    topoData.load(fileName);
    TopoFigure topoFigure;
    topoFigure.load(topoData);
    centralWidget->initFigure(topoFigure);
}
