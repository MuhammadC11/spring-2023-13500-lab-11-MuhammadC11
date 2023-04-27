#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile(std::string user, std::string dspn)
{
    username = user;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
}

std::string Profile::getUsername()
{
    return username;
}

std::string Profile::getFullName()
{
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(std::string dispn)
{
    displayname = dispn;
}