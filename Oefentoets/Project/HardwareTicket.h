//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_HARDWARETICKET_H
#define TOETS_HARDWARETICKET_H


#include "Ticket.h"

class HardwareTicket : public Ticket {
private:
    int computerId;

public:
    void output() const override;
};


#endif //TOETS_HARDWARETICKET_H
