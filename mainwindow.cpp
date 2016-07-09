#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QApplication>

extern MainWindow *w;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    m_thread = new Thread_test(this);
    m_thread->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Packet_data(char * s_mac, char * d_mac, char * e_type, char * s_ip, char * d_ip, char* ip_type, char* s_port, char* d_port){


    int temp = ui->tableWidget->rowCount();
    //printf("XXXXXXXXX %s\n",s_mac);
    ui->tableWidget->setRowCount(temp+1);;
    ui->tableWidget->setColumnCount(8);

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("src_mac"));
    ui->tableWidget->setItem(temp,0,new QTableWidgetItem(s_mac));

    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("des_mac"));
    ui->tableWidget->setItem(temp,1,new QTableWidgetItem(d_mac));

    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Ethernet_type"));
    ui->tableWidget->setItem(temp,2,new QTableWidgetItem(e_type));

    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("src_ip"));
    ui->tableWidget->setItem(temp,3,new QTableWidgetItem(s_ip));

    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("des_ip"));
    ui->tableWidget->setItem(temp,4,new QTableWidgetItem(d_ip));

    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("IP_type"));
    ui->tableWidget->setItem(temp,5,new QTableWidgetItem(ip_type));

    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Src_port"));
    ui->tableWidget->setItem(temp,6,new QTableWidgetItem(s_port));

    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("des_port"));
    ui->tableWidget->setItem(temp,7,new QTableWidgetItem(d_port));

    ui->tableWidget->resizeColumnsToContents();
    //printf("[+] %d\n",temp);

}
