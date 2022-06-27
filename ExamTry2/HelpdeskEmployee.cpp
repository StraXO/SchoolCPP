//
// Created by Thomas Holtkamp on 6/27/2022.
//

#include "HelpdeskEmployee.h"

#include <utility>
#include <iostream>

HelpdeskEmployee::HelpdeskEmployee(std::string name, std::string password, std::string department, std::string expertise) : Employee(std::move(name), std::move(password), std::move(department)), expertise(std::move(expertise)) {}

void HelpdeskEmployee::output() const {
    std::cout<< "\t" << getName() << " (" << getDepartment() << ", Expertise: " << getExpertise() << ")";
}

const std::string &HelpdeskEmployee::getExpertise() const {
    return expertise;
}

void HelpdeskEmployee::setExpertise(const std::string &expertise) {
    HelpdeskEmployee::expertise = expertise;
}
