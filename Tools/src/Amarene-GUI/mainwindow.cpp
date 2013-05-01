#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

int MainWindow::on_evalbutton_clicked()
{
    QString filex;

    if(ui->line->text() == "")
    {
        filex = QFileDialog::getOpenFileName(this, tr("Choose a file to open."), QString(), tr("RSBXL2 Files (*.rsbxl2)"));
        ui->line->setText(filex);
    }

    filex = ui->line->text();
    QMessageBox box;
    box.setText(tr("Error: File was not chosen."));
    box.setIcon(QMessageBox::Warning);
    int res = processFile(filex);

    if(res == -1)
    {
        box.exec();
    }
    else if(res == -2)
    {
        box.setText(tr("Error: Could not open file."));
        box.setIcon(QMessageBox::Critical);
        box.exec();
    }
    return 0;
}

int MainWindow::on_clearbutton_clicked()
{
    ui->namebox->setText("");
    ui->agebox->setText("");
    ui->latesttestbox->setText("");
    ui->resultfilebox->setText("");
    return 0;
}

int MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
    return 0;
}

int MainWindow::processFile(QString filex)
{
    if(filex == "")
    {
        return -1;
    }

    QFile file(filex);
    QString t;
    if(file.open(QIODevice::ReadOnly /*| QIODevice::Text*/))
    {
        int xan = 0;
        while(!file.atEnd())
        {
            t = file.readLine();
            switch(xan)
            {
                case 0:
                    ui->namebox->setText(t);
                case 1:
                    ui->agebox->setText(t);
                case 2:
                    ui->latesttestbox->setText(t);
                case 3:
                    ui->resultfilebox->setText(t);
                case 4:
                    break;
            }
            xan++;
        }
        return 0;
    }
    else
    {
        return -2;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
