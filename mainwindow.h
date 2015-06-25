#ifndef MAINWINDOW_H
#define MAINWINDOW_H


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

    //GLWidget *centralWidget;

private slots:
    void on_openTopoButton_clicked();
    void on_openUrbanButton_clicked();
};

#endif // MAINWINDOW_H
