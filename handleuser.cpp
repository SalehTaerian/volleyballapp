#include "handleuser.h"

handleuser::handleuser() {}
void handleuser::addUser(QString firstname , QString lastname , QString phonenumber , QString date , int sessions)
{
    user userobj(firstname , lastname , phonenumber , date , sessions);
    users.push_back(userobj);
}
void handleuser::deleteUser(user& userobj)
{
    users.removeOne(userobj);
}
// void handleuser::editUser(user userobj)
// {
    
// }
