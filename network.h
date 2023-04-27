#pragma once
#include <iostream>
#include "profile.h"

class Network
{ // Create a class called Network
private:
    static const int MAX_USERS = 20;      // Maximum number of user profiles
    int numUsers;                         // Number of registered users
    Profile profiles[MAX_USERS];          // User profiles array
    bool following[MAX_USERS][MAX_USERS]; // Friendship matrix

    int findID(std::string usrn); // Return the index of the user with username usrn, or -1 if no such user exists.

public:
    Network(); // Constructor, make an empty network (numUsers = 0)

    bool addUser(std::string usrn, std::string dspn); // Add a new user to the network

    bool follow(std::string usrn1, std::string usrn2); // Record that usr1 follows usr2

    void printDot(); // Prints the network in a format suitable for input to the "dot" command of graphviz.

    void printDot(std::string filename); // Prints the network in a format suitable for input to the "dot" command of graphviz.
};
