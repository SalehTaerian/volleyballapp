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
#include<QDate>
using namespace std;
class handleuser:public QObject
{
    Q_OBJECT
private:
    QVector<user> users;
public:
    handleuser();
    QVector<user> getuser();
    Q_INVOKABLE void addUser(QString firstname , QString lastname  , QString phonenumber  , QString date ,int sessions ,int days);
    Q_INVOKABLE int deleteUser(QString phonenumber);
    Q_INVOKABLE void deleteUserFromDb(QString phonenumber);
    // Q_INVOKABLE void connectToDb();
    Q_INVOKABLE void inserttodb(QString firstname , QString lastname , QString phonenumber , QString date , int sessions , int days);
    // Q_INVOKABLE void editUser();
    Q_INVOKABLE void showusers();
    Q_INVOKABLE QString getUser(int index  , int item);
    Q_INVOKABLE void readFromDatabase();
    Q_INVOKABLE int getNumberOfUser();
    Q_INVOKABLE QString convertToLastDatDay1(QString firstDate , int sessions);
    Q_INVOKABLE QString convertToLastDatDay2(QString firstDate , int sessions);
    Q_INVOKABLE QString convertToLastDatDay3(QString firstDate , int sessions);
    Q_INVOKABLE QDate firstSundayOrTuesday(QDate &firstStep);
    Q_INVOKABLE QDate firstSundayOrThursday(QDate &firstStep);
    Q_INVOKABLE QDate firstThursdayOrTuesday(QDate &firstStep);

};
#endif // HANDLEUSER_H
