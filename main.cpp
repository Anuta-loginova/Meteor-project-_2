#include "mainwindow.h"
#include"QSplashScreen"
#include "qsplashscreen.h"
#include <QApplication>
#include<QThread>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QPixmap pixmap(":/images/Adjektivdeklination_alle_Deklinationstypen_in_einer_Tabelle.png");// картинка для заставки
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
