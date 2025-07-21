#ifndef USER_H
#define USER_H
#include<QString>
#include <QObject>

class user : public QObject
{
    Q_OBJECT
private:
    QString firstname;
    QString lastname;
    QString phonenumber;
    QString date;
public:
    user();
    explicit user(QString firstname , QString lastname , QString phonenumber ,QString date ,QObject *parent = nullptr);
    Q_INVOKABLE void setfirstname(QString firstname);
    Q_INVOKABLE void setlastname(QString lastname);
    Q_INVOKABLE void setphonenumber(QString phonenumber);
    Q_INVOKABLE void setnewdate(QString date);
    Q_INVOKABLE QString getfirstname();
    Q_INVOKABLE QString getlastname();
    Q_INVOKABLE QString getphonenumber();
    Q_INVOKABLE QString getnewdate();
};

#endif // USER_H
