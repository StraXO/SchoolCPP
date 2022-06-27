//
// Created by Thomas Holtkamp on 6/27/2022.
//

#include <iostream>
#include "Ticket.h"

Ticket::Ticket(int id, const std::string& date, const std::string& description, std::shared_ptr<Employee> creator) :
id(id), date(date), description(description), creator(creator){}

int Ticket::getId() const {
    return id;
}

void Ticket::setId(int id) {
    Ticket::id = id;
}

const std::string &Ticket::getDate() const {
    return date;
}

void Ticket::setDate(const std::string &date) {
    Ticket::date = date;
}

const std::string &Ticket::getDescription() const {
    return description;
}

void Ticket::setDescription(const std::string &description) {
    Ticket::description = description;
}

const std::shared_ptr<Employee> &Ticket::getCreator() const {
    return creator;
}

void Ticket::setCreator(const std::shared_ptr<Employee> &creator) {
    Ticket::creator = creator;
}

const std::shared_ptr<HelpdeskEmployee> &Ticket::getSolver() const {
    return solver;
}

void Ticket::setSolver(const std::shared_ptr<HelpdeskEmployee> &solver) {
    Ticket::solver = solver;
}

const std::string &Ticket::getSolvedMessage() const {
    return solvedMessage;
}

void Ticket::setSolvedMessage(const std::string &solvedMessage) {
    Ticket::solvedMessage = solvedMessage;
}

std::string Ticket::getStatus() const {
    if (getSolver() == nullptr)
        return "Open";

    return "Solved";
}
