//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_HELPDESK_H
#define TOETS_HELPDESK_H


#include <vector>
#include <memory>
#include "Ticket.h"

class HelpDesk {
private:
    std::vector<Ticket> tickets;
    std::vector<std::unique_ptr<Medewerker>> medewerkers;
};


#endif //TOETS_HELPDESK_H
