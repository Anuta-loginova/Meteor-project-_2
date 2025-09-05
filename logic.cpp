
#include <QString>
#include "logic.h"

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
        return "you are idiot";
    }
}
