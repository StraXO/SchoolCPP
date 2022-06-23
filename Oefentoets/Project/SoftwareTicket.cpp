//
// Created by Thomas Holtkamp on 6/23/2022.
//

#include <iostream>
#include "SoftwareTicket.h"

void SoftwareTicket::output() const {
    std::cout << "\tTicket: " << this->ticketNummer << "(Softwareticket, Application:" << this->softwarePakket << "):" << std::endl;
    Ticket::common_output();
}