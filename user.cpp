#include "user.h"

user::user(QString firstname , QString lastname , QString phonenumber ,QString date ,QObject *parent)
    : QObject{parent}
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->date = date;
    this->phonenumber = phonenumber;
}
user::user()
{
    this->firstname = "saleh";
    this->lastname = "taerian";
    this->date = "1403/02/13";
    this->phonenumber = "09133325279";
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
QString user::getfirstname()
{
    return firstname;
}
QString user::getlastname()
{
    return lastname;
}
QString user::getphonenumber()
{
    return phonenumber;
}
QString user::getnewdate()
{
    return date;
}
