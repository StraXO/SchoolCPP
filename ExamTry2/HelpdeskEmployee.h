//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef TOETS_HELPDESKEMPLOYEE_H
#define TOETS_HELPDESKEMPLOYEE_H

#include "Employee.h"

class HelpdeskEmployee : public Employee {
    std::string expertise;

public:
    HelpdeskEmployee(std::string name, std::string password, std::string department, std::string expertise);
    ~HelpdeskEmployee() override = default;

    void output() const override;

    const std::string &getExpertise() const;

    void setExpertise(const std::string &expertise);
};


#endif //TOETS_HELPDESKEMPLOYEE_H
