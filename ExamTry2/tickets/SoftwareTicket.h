//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef TOETS_SOFTWARETICKET_H
#define TOETS_SOFTWARETICKET_H


#include <string>
#include "../Ticket.h"

class SoftwareTicket : public Ticket {
    std::string softwarePackage;

public:
    SoftwareTicket(int id, const std::string &date, const std::string &description, const std::shared_ptr<Employee>& creator, const std::string& softwarePackage);
    ~SoftwareTicket() override = default;

    void output() const override;

    const std::string &getSoftwarePackage() const;

    void setSoftwarePackage(const std::string &softwarePackage);
};


#endif //TOETS_SOFTWARETICKET_H
