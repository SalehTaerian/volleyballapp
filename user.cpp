#include "user.h"
user::user(QString firstname , QString lastname , QString phonenumber ,QString firstsession ,QString date ,int sessions ,int days)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->date = date;
    this->phonenumber = phonenumber;
    this->firstsession = firstsession;
    this->sessions = sessions;
    this->days = days;
}
user::user()
{
    this->firstname = "saleh";
    this->lastname = "taerian";
    this->date = "1403/02/13";
    this->phonenumber = "09133325279";
    firstsession = "1404/01/01";
    sessions = 1;
    days=1;
}
user::user(const user& usertemp)
{
    firstname =usertemp.firstname;
    lastname = usertemp.lastname;
    phonenumber =usertemp.phonenumber;
    firstsession  = usertemp.firstsession;
    date = usertemp.date;
    sessions = usertemp.sessions;
    days = usertemp.days;
}
void user::setfirstname(QString firstname)
{
    this->firstname = firstname;
}
void user::setlastname(QString lastname)
{
    this->lastname = lastname;
}
void user::setphonenumber(QString phonenumber)
{
    this->phonenumber = phonenumber;
}
void user::setnewdate(QString date)
{
    this->date = date;
}
QString user::getfirstname()const
{
    return firstname;
}
QString user::getlastname()const
{
    return lastname;
}
QString user::getphonenumber()const
{
    return phonenumber;
}
QString user::getnewdate()const
{
    return date;
}
void user::setsessions(int sessions)
{
    this->sessions = sessions;
}
int user::getsessions()const
{
    return sessions;
}
QString user::getfirstsession()
{
    return firstsession;
}
bool user::operator==(const user& usertemp)const
{
    return firstname==usertemp.firstname  && lastname==usertemp.lastname && date==usertemp.date && phonenumber==usertemp.phonenumber;
}
QString user::getdays()
{
    QString day1 = "یکشنبه و"
                   " سه شنبه";
    QString day2 = "یکشنبه و"
                   " پنجشنبه";
    QString day3 = "سه شنبه و"
                   " پنجشنبه";
    if(days==1)
    {
        return day1;
    }
    else if(days==2)
    {
        return day2;
    }
    else if(days==3)
    {
        return day3;
    }
}
