#include "ManageUsersData.h"
#include "exception"
void ManageUsersData::isExsistUserAndPAsswordIsCorrect(string username, string password)
{
    auto u = usersTree.findNode(User{ username,password});
    if (u == nullptr)
        throw exception("not Exist this username");
    else if (!u->val.validatePassword(password))
        throw exception("is exist and password is incorrect");
    else
        std::cout << "username is: " << username << " password is: " << password << std::endl;
}
