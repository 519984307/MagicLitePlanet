﻿/***************************************************/
/*              Magic Light Assistant              */
/* Copyright (c) 2017-2021 by bytecho.net          */
/* Written by Henry                                */
/* Function:                                       */
/* Communication, activity, management and approval*/
/***************************************************/
#pragma once
#pragma execution_character_set("utf-8")

#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QtSql>
#include <QtCharts>
#include <QSettings>
#include <QPainter>
#include <QCryptographicHash>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_CHARTS_USE_NAMESPACE

class service
{
public:
    static QString pwdEncrypt(const QString& str);  //字符串加密

    void connectDatabase(QSqlDatabase& db);
    
    void addDatabase(QSqlDatabase& db, const QString &flag);

    static bool initDatabaseTables(QSqlDatabase db);

    //验证返回状态码：200验证成功；400账号封禁；403账号密码不匹配；500网络错误
    static int authAccount(QSqlDatabase& db, QString& uid, const long long account, const QString& pwd);

    static bool setAuthority(QSqlDatabase& db, const QString& uid, const QVector<QAction *> &vector);

    static QPixmap getAvatar(const QString& url);

    static QPixmap setAvatarStyle(QPixmap);

    static QString getGroup(const QString& uid);

    static QString getDepartment(const QString& uid);

    static void buildAttendChart(QChartView* chartView_attend, const QWidget* parent, const QFont& font, int data_1, int data_2, int data_3, int data_4);

    service();

private:

    QSqlDatabase db;
    QString dataBaseType;
    QString hostName;
    int dataBasePort;
    QString dataBaseName;
    QString dataBaseUserName;
    QString dataBasePassword;

};

#endif // SERVICE_H
