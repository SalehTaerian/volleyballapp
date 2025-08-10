#pragma once
#ifndef USER_H
#define USER_H
#include<QString>
#include <QObject>

class user
{
private:
    QString firstname;
    QString lastname;
    QString phonenumber;
    QString firstsession;
    QString date;
    int sessions;
    int days;
public:
    user();
    user(QString firstname , QString lastname , QString phonenumber ,  QString firstsession ,QString date ,int sessions , int days);
    user(const user& usertemp);
    void setfirstname(QString firstname);
    void setlastname(QString lastname);
    void setphonenumber(QString phonenumber);
    void setnewdate(QString date);
    void setsessions(int sessions);
    int getsessions()const;
    QString getfirstname()const;
    QString getlastname()const;
    QString getphonenumber()const;
    QString getfirstsession();
    QString getnewdate()const;
    QString getdays();
    bool operator==(const user& usertemp)const;
};

#endif // USER_H
