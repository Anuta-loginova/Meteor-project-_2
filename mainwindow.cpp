#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Logic logic;
    QString message = logic.getMessage();

    ui->lable_1->setText(message);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_columnView_updatePreviewWidget(const QModelIndex &index)
{

}

