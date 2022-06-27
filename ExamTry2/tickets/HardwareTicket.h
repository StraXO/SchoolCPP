//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef TOETS_HARDWARETICKET_H
#define TOETS_HARDWARETICKET_H


#include "../Ticket.h"

class HardwareTicket : public Ticket {
    int computerId;

public:
    HardwareTicket(int id, const std::string &date, const std::string &description, const std::shared_ptr<Employee> &creator, int computerId);
    ~HardwareTicket() override = default;

    void output() const override;

    int getComputerId() const;

    void setComputerId(int computerId);
};


#endif //TOETS_HARDWARETICKET_H
