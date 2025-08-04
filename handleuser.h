#pragma once
#ifndef HANDLEUSER_H
#define HANDLEUSER_H
#include<iostream>
#include<QVector>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include"user.h"
using namespace std;
class handleuser:public QObject
{
    Q_OBJECT
private:
    QVector<user> users;
public:
    handleuser();
    QVector<user> getuser();
    Q_INVOKABLE void addUser(QString firstname , QString lastname  , QString phonenumber  , QString date ,int sessions);
    Q_INVOKABLE void deleteUser(user& userobj);
    // Q_INVOKABLE void connectToDb();
    Q_INVOKABLE void inserttodb(QString firstname , QString lastname , QString phonenumber , QString date , int sessions);
    // Q_INVOKABLE void editUser();
    Q_INVOKABLE void showusers();
    Q_INVOKABLE QString getUser(int index  , int item);
    Q_INVOKABLE void readFromDatabase();
    Q_INVOKABLE int getNumberOfUser();
};
#endif // HANDLEUSER_H
