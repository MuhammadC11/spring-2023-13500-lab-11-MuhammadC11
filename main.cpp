#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main()
{
    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << "\n";
    std::cout << p1.getFullName() << "\n";

    p1.setDisplayName("Marco Rossi");
    std::cout << p1.getUsername() << "\n";
    std::cout << p1.getFullName() << "\n";

    Profile p2("tarma1", "Tarma Roving");
    std::cout << p2.getUsername() << "\n";
    std::cout << p2.getFullName() << "\n";

    Network nw1;
    std::cout << nw1.addUser("mario", "Mario") << "\n";
    std::cout << nw1.addUser("luigi", "Luigi") << "\n";

    std::cout << nw1.addUser("mario", "Mario2") << "\n";

    std::cout << nw1.addUser("mario 2", "Mario2") << "\n";

    std::cout << nw1.addUser("mario-2", "Mario2") << "\n";

    for (int i = 2; i < 20; i++)
        std::cout << nw1.addUser("mario" + std::to_string(i),
                                 "Mario" + std::to_string(i))
                  << "\n";

    std::cout << nw1.addUser("yoshi", "Yoshi") << "\n";

    Network nw;

    nw.addUser("mario", "Mario");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");

    for (int i = 2; i < 6; i++)
    {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }

    nw.follow("mario2", "luigi");

    nw.printDot();
}