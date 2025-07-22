#ifndef HANDLEUSER_H
#define HANDLEUSER_H
#include<iostream>
#include<QVector>
#include <QObject>
#include"user.h"
using namespace std;
class handleuser:public QObject
{
    Q_OBJECT
private:
    QVector<user> users;
public:
    handleuser();
    Q_INVOKABLE void addUser(QString firstname , QString lastname  , QString phonenumber  , QString date ,int sessions);
    Q_INVOKABLE void deleteUser(user& userobj);
    // Q_INVOKABLE void editUser();
};
#endif // HANDLEUSER_H
