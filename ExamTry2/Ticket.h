//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef TOETS_TICKET_H
#define TOETS_TICKET_H


#include <string>
#include <memory>
#include "Employee.h"

class Ticket {
    int id;
    std::string date;
    std::string description;
    std::shared_ptr<Employee> creator;
    std::shared_ptr<Employee> solver;
    std::string solvedMessage;

public:
    Ticket(int id, const std::string& date, const std::string& description, std::shared_ptr<Employee> creator);
    virtual ~Ticket() = default;

    std::string getStatus() const;
    virtual void output() const = 0;

    int getId() const;

    void setId(int id);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::shared_ptr<Employee> &getCreator() const;

    void setCreator(const std::shared_ptr<Employee> &creator);

    const std::shared_ptr<Employee> &getSolver() const;

    void setSolver(const std::shared_ptr<Employee> &solver);

    const std::string& getSolvedMessage() const;

    void setSolvedMessage(const std::string &solvedMessage);
};


#endif //TOETS_TICKET_H
