#include <iostream>
#include <string>
#include "network.h"
#include "profile.h"

int Network::findID(std::string usrn)
{
    for (int i = 0; i < numUsers; i++) // Loop through all profiles
    {
        if (profiles[i].getUsername() == usrn) // If the username of the current profile matches the username we are looking for
        {
            return i; // Return the index of the profile
        }
    }
    return -1; // If no profile is found, return -1
}

Network::Network() // Constructor, make an empty network (numUsers = 0)
{
    numUsers = 0; // Set the number of users to 0
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    if (numUsers == MAX_USERS) // If the number of users is equal to the maximum number of users
    {
        return false; // Return false
    }
    for (int i = 0; i < numUsers; i++) // Loop through all profiles
    {
        if (profiles[i].getUsername() == usrn) // If the username of the current profile matches the username we are looking for
        {
            return false; // Return false
        }
    }
    profiles[numUsers] = Profile(usrn, dspn); // Create a new profile with the username and display name
    numUsers++;                               // Increment the number of users
    return true;                              // Return true
}

bool Network::follow(std::string usrn1, std::string usrn2) // Record that usr1 follows usr2
{
    int id1 = findID(usrn1);    // Find the index of the first user
    int id2 = findID(usrn2);    // Find the index of the second user
    if (id1 == -1 || id2 == -1) // If either user is not found
    {
        return false; // Return false
    }
    following[id1][id2] = true; // Set the following matrix to true
    return true;                // Return true
}

void Network::printDot()
{
    std::cout << "digraph {" << std::endl; // Print the opening of the graph
    for (int i = 0; i < numUsers; i++)
    {
        std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl; // Print the username of the current profile
    }
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numUsers; j++) // Loop through all profiles
        {
            if (following[i][j]) // If the current profile is following the other profile

            {
                std::cout << "  \"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << std::endl; // Print the username of the current profile and the username of the other profile
            }
        }
    }
    std::cout << "}" << std::endl; // Print the closing of the graph
}
