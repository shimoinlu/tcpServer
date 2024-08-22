#include "ManageUsersData.h"
#include "exception"
void ManageUsersData::isExistUserAndPasswordIsCorrect(string username, string password)
{
    if(!SearchUser(username))
        throw exception("not exist this username");
    else if (!usersTree.findNode(User{ username,"" })->val.validatePassword(password))
        throw exception("is exist and password is incorrect");
    else
        std::cout << "username is: " << username << " password is: " << password << std::endl;
}



bool ManageUsersData::SearchUser(string username)
{
    auto u = usersTree.findNode(User{ username,""});
    return u != nullptr;
}

void ManageUsersData::pushMessage(string from, string username, string message)
{
    auto targetUser = usersTree.findNode(User{ username,""});
    Message msg(from, message);
    targetUser->val.addMessage(msg);
}
