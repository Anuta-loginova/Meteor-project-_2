#include "mainwindow.h"
#include"QSplashScreen"
#include "qsplashscreen.h"
#include <QApplication>
#include<QThread>
#include<QSplashScreen>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QPixmap pixmap(400, 300); // размер окна заставки
    pixmap.fill(Qt::lightGray);
    SplashScreen splash(pixmap);
    splash.show();


    // Можно показывать сообщения
    splash.showMessageText("Загрузка модулей...");
    QThread::sleep(1); // имитация загрузки
    splash.showMessageText("Инициализация интерфейса...");
    QThread::sleep(1);
    a.processEvents();

    // имитируем загрузку (например, чтение из базы/инициализация)
    QThread::sleep(2);
    MainWindow w;
    w.show();


    splash.finish(&w);
    return a.exec();
}
