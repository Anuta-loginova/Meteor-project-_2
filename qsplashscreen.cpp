#include "qsplashscreen.h"

SplashScreen::SplashScreen(const QPixmap &pixmap)
    : QSplashScreen(pixmap)
{
    // Можно задать стиль текста, цвет, шрифт
    this->setFont(QFont("Arial", 12, QFont::Bold));
}

void SplashScreen::showMessageText(const QString &text)
{
    this->showMessage(text, Qt::AlignBottom | Qt::AlignHCenter, Qt::white);
}
