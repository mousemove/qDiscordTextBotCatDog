#include "discordbotcatdog.h"

discordbotCatDog::discordbotCatDog(QString prefix,QObject *parent):discordBotAbstractStrategy(prefix,parent)
{
    srand(time(NULL));
    {
        QFile file("caturls.txt");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                QString str = file.readLine();
                str.remove("\n");
                catUrls.push_back(str);
            }

        }
        else
        {
            catUrls.push_back("there are no cats in database ;(");
        }
    }
    QFile file("dogurls.txt");
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        while(!file.atEnd())
        {
            QString str = file.readLine();
            str.remove("\n");
            dogUrls.push_back(str);
        }

    }
    else
    {
        dogUrls.push_back("there are no dogs in database ;(");
    }
}

void discordbotCatDog::processMessage(QString type, QString data)
{
    json j = json::parse(data.toStdString());
    if(type == "MESSAGE_CREATE")
    {
        QString author =  QString::fromStdString(j["author"]["id"]);

        if(author != _id && (j["content"] == _prefix.toStdString()+"cat" ||j["content"] == _prefix.toStdString()+"dog")){
            QString message = QString::fromStdString(j["content"]);//сообщение пользователя
            if (message.contains("cat"))
            {
                message = catUrls.at(rand() % (catUrls.size()));
            }
            else
            {
                message = dogUrls.at(rand() % (dogUrls.size()));
            }
            QString id = QString::fromStdString(j["id"]);
            QString channel_id = QString::fromStdString(j["channel_id"]);
            emit sendTextMessage(message,"",channel_id);
            qDebug() << message;

        }

    }

}
