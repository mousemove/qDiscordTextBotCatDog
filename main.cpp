#include <QCoreApplication>
#include "discordbot.h"
#include "discordbotcatdog.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    discordBot d("==your token here=====",new discordbotCatDog("!"));
    return a.exec();
}
