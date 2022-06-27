#include <iostream>
#include <fstream>
#include <memory>
#include "Helpdesk.h"

int main()
{
    /**
     *
     * Add method calls to your administration class below. Your program should perform the given
     * steps. Please also handle errors and print the error message when something went wrong!
     * Possible errors are:
     *  - Adding users with duplicate usernames
     *  - TODO
     *  - Errors reading the input file (In this case the file is ok, but maybe in the future we will use a wrong file)
     */

    // Create an instance of the helpdesk admin class
    Helpdesk helpdesk;

    //Read the (normal) employees from the employees.txt file
    helpdesk.readEmployees("input.txt");

    //Add the following helpdesk employees (They are all working on the helpdesk-department)
    //username: gerralt, password: catsarecool, expertise: Mice
    helpdesk.addHelpdeskEmployee("gerralt", "catsarecool", "Helpdesk", "Mice");

    //Print all employees
    helpdesk.printEmployees();
    std::cout << std::endl;

    //Add the following tickets. Start with id 1
    helpdesk.addSoftwareTicket("15-01-2018", "ruud", "Excel can't calculate the number of days in a year", "Office 365");
    helpdesk.addHardwareTicket("16-01-2018", "jeroen", "My mouse doesn't work!", 5);
    helpdesk.addSoftwareTicket("17-01-2018", "ruud", "MacOS won't boot on my system", "MacOS X");

    //Solve ticket 2 and 3 (The last two)
    helpdesk.solveTicket(2, "gerralt", "Try putting it into the USB port instead of the HDMI port.");
    helpdesk.solveTicket(3, "gerralt", "Please replace your Dell laptop with a real system");

    //Print the tickets
    helpdesk.printTickets();

    return 0; // TODO: make sure all allocated memory gets freed at the end of this function
}
