//
// Created by Thomas Holtkamp on 6/23/2022.
//

#include <iostream>
#include "Ticket.h"

std::string Ticket::getStatus() const {
    if (this->oplosser == nullptr) {
        return "Open";
    } else {
        return "Closed";
    }
}

void Ticket::common_output() const {
    std::cout << "Status: " << this->getStatus() << std::endl;
    std::cout << this->melder->getNaam() << "(" << this->melder->getAfdeling() << "): " << probleemBeschrijving << std::endl;
    if (this->oplosser != nullptr) {
        std::cout << this->oplosser->getNaam() << "(" << this->oplosser->getAfdeling() << ", " << this->oplosser->getExpertise() << "): " << oplossingBeschrijving << std::endl;
    }
}
