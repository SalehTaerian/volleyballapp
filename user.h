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
    QString date;
    int sessions;
public:
    user();
    user(QString firstname , QString lastname , QString phonenumber ,QString date ,int sessions);
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
    QString getnewdate()const;
    bool operator==(const user& usertemp)const;
};

#endif // USER_H
