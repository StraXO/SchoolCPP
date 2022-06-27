//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef EXAMTRY2_HELPDESK_H
#define EXAMTRY2_HELPDESK_H


#include <vector>
#include <memory>
#include "Employee.h"
#include "Ticket.h"
#include "HelpdeskEmployee.h"

class Helpdesk {
private:
    std::vector<std::shared_ptr<Employee>> employees;
    std::vector<std::shared_ptr<Ticket>> tickets;
    unsigned int next_id = 0;

public:
    void readEmployees(const std::string& fileName);

    void addHelpdeskEmployee(const std::string &name, const std::string &password, const std::string &department,
                             const std::string &expertise);

    void printEmployees() const;
    void printTickets() const;

    void addSoftwareTicket(const std::string& date, const std::string& creator, const std::string& description, const std::string& software);
    void addHardwareTicket(const std::string& date, const std::string& creator, const std::string& description, const int computerId);

    std::shared_ptr<Employee> findEmployee(const std::string &name) const;
    std::shared_ptr<HelpdeskEmployee> findHelpDeskEmployee(const std::string &name) const;
    std::shared_ptr<Ticket> findTicket(int id) const;
    void solveTicket(int id, const std::string& solver, const std::string& message) const;

    unsigned int getNextTicketId() {
        return ++next_id;
    }
};


#endif //EXAMTRY2_HELPDESK_H
