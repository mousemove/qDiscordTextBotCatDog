#ifndef DISCORDBOTCATDOG_H
#define DISCORDBOTCATDOG_H

#include <QObject>
#include "discordbotabstractstrategy.h"
#include "additional/json.hpp"
#include <QFile>
#include <cstdlib>
#include <QDebug>
using namespace nlohmann;
class discordbotCatDog : public discordBotAbstractStrategy
{
    Q_OBJECT
private:
   QVector<QString> catUrls;
   QVector<QString> dogUrls;
public:
    discordbotCatDog(QString prefix = "",QObject *parent = nullptr);
public slots:
  virtual void processMessage(QString type,QString data) override;
};

#endif // DISCORDBOTCATDOG_H
