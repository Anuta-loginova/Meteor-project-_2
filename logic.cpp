#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <QString>
#include "logic.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <QString>


Logic::Logic()
{
    // конструктор (если нужен)
}
int x = 5;
int y = 4;
QString Logic::getMessage()
{   if (x <= y ){
    return "Привет, это сообщение из логики!";
    }
    else {
        return "NASA Database";
    }
}
void MainWindow::parseAndShowData(const QByteArray &data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return;

    QJsonObject obj = doc.object();

    QJsonArray dataArr = obj["data"].toArray();

    ui->tableWidget->setRowCount(dataArr.size());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Date", "Distance (AU)", "Velocity (km/s)"});

    for (int i = 0; i < dataArr.size(); ++i)
    {
        QJsonArray row = dataArr[i].toArray();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(row[0].toString())); // Name
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(row[3].toString())); // Date
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(row[4].toString())); // Distance
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(row[7].toString())); // Velocity
    }

    ui->tableWidget->resizeColumnsToContents();
}
