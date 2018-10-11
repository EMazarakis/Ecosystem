#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QString>
#include<QChar>

#include"plants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fName = "example.txt";

    QFile file("C:\\Users\\user\\MyGit\\Ecosystem\\TEXT\\example.txt");

    if( !file.open(QIODevice::ReadOnly) ){  //if sth wrong happened

        QMessageBox::information(0,"info",file.errorString());
    }

    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());     //read everything inside the file

    ui->label->setText(fName);
}



void MainWindow::on_pushButton_2_clicked()  //run program button
{
    QString tmp1=" ";
    QString nLine=" ";
    Plants myFito('A',10,15,20,25);

    myFito.printMembersPlants();


    tmp1 =  QChar(myFito.getToken());
    ui->textBrowser_2->append(tmp1);
    ui->textBrowser_2->append(nLine);

    tmp1 = QString::number( myFito.getBreedProb() );   //display the brredProbability
    ui->textBrowser_2->append(tmp1);
    ui->textBrowser_2->append(nLine);

    tmp1 = QString::number( myFito.getIllProb() );
    ui->textBrowser_2->append(tmp1);
    ui->textBrowser_2->append(nLine);

    tmp1 = QString::number( myFito.getLife() );
    ui->textBrowser_2->append(tmp1);
    ui->textBrowser_2->append(nLine);

    tmp1 = "Life factor: " + QString::number( myFito.getLifeFactor() );
    ui->textBrowser_2->append(tmp1);
    ui->textBrowser_2->append(nLine);


    tmp1 = "@#@@@@@@@#";
    ui->textBrowser_2->append(tmp1);
    tmp1 = "@@@^@@@@#^";
    ui->textBrowser_2->append(tmp1);


    //TODO: RUN THE ECOSYSTEM
}







