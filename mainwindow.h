#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void initMenuBar();
    void initCentralWidget();
    void initToolBar();
    GLWidget *centralWidget;

private slots:
    void openFile();

};

#endif // MAINWINDOW_H
