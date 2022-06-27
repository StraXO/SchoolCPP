//
// Created by Thomas Holtkamp on 6/27/2022.
//

#include <iostream>
#include "HardwareTicket.h"

HardwareTicket::HardwareTicket(int id, const std::string &date, const std::string &description,const std::shared_ptr<Employee> &creator, int computerId) : Ticket(id, date, description, creator), computerId(computerId) {}

void HardwareTicket::output() const {
    std::cout << "\tTicket " << getId() << " (Hardwareticket, computerId: " << getComputerId() << "):" << std::endl;
    std::cout << "\t\tStatus: " << getStatus() << std::endl;

    std::cout << "\t";
    getCreator()->output();
    std::cout << ": " << getDescription() << std::endl;

    if (getSolver() != nullptr) {
        std::cout << "\t";
        getSolver()->output();
        std::cout << ": " << getSolvedMessage() << std::endl;
    }
}

int HardwareTicket::getComputerId() const {
    return computerId;
}

void HardwareTicket::setComputerId(int computerId) {
    HardwareTicket::computerId = computerId;
}
