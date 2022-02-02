#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ActiveQt_xlsx.h"


Integer GlobCnt=0;

ActiveQt_xlsx *SourceData;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //abc=ui->checkBox->text();
    //SourceData= new  ActiveQt_xlsx;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GlobCnt=GlobCnt+1;
    ui->label->setText(QString::number(GlobCnt));
}

void MainWindow::on_pushButton_2_clicked()
{
    GlobCnt=GlobCnt-1;
    ui->label->setText(QString::number(GlobCnt));
}

/*void MainWindow::on_LaunchExcelButt_clicked()
{
    GlobCnt=GlobCnt*3;
    if (SourceData==nullptr)
        SourceData= new  ActiveQt_xlsx;

}*/

void MainWindow::on_StartExcelButt_clicked()
{
    GlobCnt=GlobCnt*3;
    if (SourceData==nullptr)
        SourceData= new  ActiveQt_xlsx;
}
