#include "mainwindow.h"
#include"QSplashScreen"
#include "qsplashscreen.h"
#include <QApplication>
#include<QThread>
#include"QResource"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QPixmap pixmap(":/a1b158d7d3222b8b4b87b.png");
    if (pixmap.isNull())
        qDebug() << "Картинка не найдена!";

    SplashScreen splash(pixmap);
    splash.show();

    // Можно показывать сообщения
    splash.showMessageText("Загрузка модулей...");
    QThread::sleep(1); // имитация загрузки
    splash.showMessageText("Инициализация интерфейса...");
    QThread::sleep(1);

    splash.finish(&w);
    return a.exec();
}
