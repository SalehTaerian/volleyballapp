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
    void addUser();
    void deleteUser();
    void editUser();

};
#endif // HANDLEUSER_H
