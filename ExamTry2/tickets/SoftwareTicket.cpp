//
// Created by Thomas Holtkamp on 6/27/2022.
//

#include <iostream>
#include "SoftwareTicket.h"

SoftwareTicket::SoftwareTicket(int id, const std::string &date, const std::string &description, const std::shared_ptr<Employee> &creator, const std::string &softwarePackage) : Ticket(id, date, description, creator), softwarePackage(softwarePackage) {}

void SoftwareTicket::output() const {
    std::cout << "\tTicket " << getId() << " (Softwareticket, Application: " << getSoftwarePackage() << "):" << std::endl;
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

const std::string &SoftwareTicket::getSoftwarePackage() const {
    return softwarePackage;
}

void SoftwareTicket::setSoftwarePackage(const std::string &softwarePackage) {
    SoftwareTicket::softwarePackage = softwarePackage;
}
