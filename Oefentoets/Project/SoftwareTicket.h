//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_SOFTWARETICKET_H
#define TOETS_SOFTWARETICKET_H


#include "Ticket.h"

class SoftwareTicket : public Ticket {
private:
    std::string softwarePakket;

public:
    void output() const override;
};


#endif //TOETS_SOFTWARETICKET_H
