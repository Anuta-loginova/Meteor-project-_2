#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"logic.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    fetchData();
    Logic logic;
    QString message = logic.getMessage();

    ui->lable_1->setText(message); // выводим в QLabel
}

MainWindow::~MainWindow()
{
    delete ui;
}





