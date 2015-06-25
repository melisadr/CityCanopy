#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "topodatamanager.h"
#include "topofigure.h"
#include "urbandatamanager.h"
#include "urbanfigure.h"

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TopoDataManager topoDataManager;
    UrbanDataManager urbanDataManager;

private slots:
    void on_openTopoButton_clicked();
    void on_openUrbanButton_clicked();
    void on_exportButton_clicked();
};

#endif // MAINWINDOW_H
