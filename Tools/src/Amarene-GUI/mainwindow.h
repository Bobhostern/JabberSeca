#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

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
    int processFile(QString file);

private slots:
    int on_evalbutton_clicked();
    int on_clearbutton_clicked();
    int on_actionQuit_triggered();
};

#endif // MAINWINDOW_H
