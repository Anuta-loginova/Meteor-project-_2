#include "read.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <QString>
#include "logic.h"

read::read() {}

void MainWindow::fetchData()
{
    QUrl url("https://ssd-api.jpl.nasa.gov/cad.api?date-min=2025-01-01&date-max=2025-12-31&dist-max=0.05");
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        QByteArray response = reply->readAll();
        parseAndShowData(response);
        reply->deleteLater();
    });
}
