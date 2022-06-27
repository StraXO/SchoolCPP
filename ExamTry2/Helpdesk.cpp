//
// Created by Thomas Holtkamp on 6/27/2022.
//
#include <fstream>
#include <iostream>
#include "Helpdesk.h"
#include "HelpdeskEmployee.h"
#include "tickets/SoftwareTicket.h"
#include "tickets/HardwareTicket.h"

void Helpdesk::readEmployees(const std::string& fileName) {
    std::ifstream input(fileName);

    while (true) {
        std::string name, password, department;
        input >> name >> password >> department;

        if (input.eof())
            break;
        if (input.fail())
            throw std::runtime_error("Error while reading file");

        employees.emplace_back(std::make_shared<Employee>(name, password, department));
    }
}

void Helpdesk::addHelpdeskEmployee(const std::string& name, const std::string& password, const std::string& department, const std::string& expertise) {
    for (auto const& employee : employees) {
        if (employee->getName() == name)
            throw std::runtime_error("Employee is already registered");
    }

    employees.emplace_back(std::make_shared<HelpdeskEmployee>(name, password, department, expertise));
}

void Helpdesk::printEmployees() const {
    std::cout << "Employees:" << std::endl;
    for (auto const& employee : employees) {
        employee->output();
        std::cout << std::endl;
    }
}

void Helpdesk::printTickets() const {
    std::cout << "Tickets:" << std::endl;
    for (auto const& ticket : tickets) {
        ticket->output();
        std::cout << std::endl;
    }
}

void Helpdesk::addSoftwareTicket(const std::string& date, const std::string& creator, const std::string& description, const std::string& software) {
    auto employee = findEmployee(creator);
    if (employee == nullptr)
        throw std::runtime_error("Employee not found");

    tickets.emplace_back(std::make_shared<SoftwareTicket>(getNextTicketId(), date, description, employee, software));
}

void Helpdesk::addHardwareTicket(const std::string &date, const std::string &creator, const std::string &description, const int computerId) {
    auto employee = findEmployee(creator);
    if (employee == nullptr)
        throw std::runtime_error("Employee not found");

    tickets.emplace_back(std::make_shared<HardwareTicket>(getNextTicketId(), date, description, employee, computerId));
}

std::shared_ptr<Employee> Helpdesk::findEmployee(const std::string &name) const {
    for (auto const& employee : employees) {
        if (employee->getName() == name)
            return employee;
    }

    return nullptr;
}

std::shared_ptr<HelpdeskEmployee> Helpdesk::findHelpDeskEmployee(const std::string &name) const {
    auto employee = findEmployee(name);
    auto resolver = std::dynamic_pointer_cast<HelpdeskEmployee>(employee);
    if (!resolver)
        throw std::runtime_error("Cannot find employee");

    return resolver;
}

void Helpdesk::solveTicket(int id, const std::string &solver, const std::string &message) const {
    auto ticket = findTicket(id);
    auto solverEmployee = findHelpDeskEmployee(solver);
    if (solverEmployee == nullptr)
        throw std::runtime_error("Could not find employee");

    ticket->setSolver(solverEmployee);
    ticket->setSolvedMessage(message);
}

std::shared_ptr<Ticket> Helpdesk::findTicket(int id) const {
    for (auto const& ticket : tickets) {
        if (ticket->getId() == id)
            return ticket;
    }

    return nullptr;
}

