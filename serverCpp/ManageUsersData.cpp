#include "ManageUsersData.h"
#include "exception"

ManageUsersData* ManageUsersData::mud = nullptr;
AVLTree<User> ManageUsersData::usersTree(FILENAME);

ManageUsersData* ManageUsersData::getInstance()
{
    if (mud == nullptr)
    {
        mud = new ManageUsersData();
        return mud;
    }
    else
        return mud;
}
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

    if (targetUser == nullptr)
    {
        string errorMessage = "not exist " + username + "select other target";
        throw exception{ errorMessage.c_str()};
    }
    Message msg(from, message);
    targetUser->val.GetMutex().lock();
    targetUser->val.addMessage(msg);
    targetUser->val.GetMutex().unlock();
}

string ManageUsersData::allMessagesAsJsonForSpecificUser(string username)
{
    mud->usersTree.findNode(User(username, ""))->val.GetMutex().lock();
    string m = mud->usersTree.findNode(User(username, ""))->val.printAllMessagesAsJson();
    mud->usersTree.findNode(User(username, ""))->val.GetMutex().unlock();
    return m;
}

int ManageUsersData::NumOfUnreadMessagesForSpecificUser(std::string username)
{
    mud->usersTree.findNode(User(username, ""))->val.GetMutex().lock();
    int num = mud->usersTree.findNode(User{username, ""})->val.unreadedMessages();
    mud->usersTree.findNode(User(username, ""))->val.GetMutex().unlock();
    return num;
}
