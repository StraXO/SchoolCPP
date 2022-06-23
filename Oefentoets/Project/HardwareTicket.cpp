//
// Created by Thomas Holtkamp on 6/23/2022.
//

#include "HardwareTicket.h"
#include <iostream>

void HardwareTicket::output() const {
    std::cout << "\tTicket: " << this->ticketNummer << "(Hardwareticket, Computerid:" << this->computerId << "):" << std::endl;
    Ticket::common_output();
}