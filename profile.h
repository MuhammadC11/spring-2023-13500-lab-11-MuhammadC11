#pragma once

#include <iostream>

class Profile
{ // Create a class called Profile
private:
    std::string username;
    std::string displayname;

public:
    Profile(std::string user, std::string dspn); // Constructor for a user

    Profile(); // Default constructor for a user

    std::string getUsername(); // Return username of the user profile

    std::string getFullName(); // Return name in the format: "displayname (@username)"

    void setDisplayName(std::string dsp); // Change display name
};