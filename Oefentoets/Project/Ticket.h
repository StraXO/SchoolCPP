//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_TICKET_H
#define TOETS_TICKET_H


#include <string>
#include <memory>
#include "Medewerker.h"
#include "Helpdeskmedewerker.h"

class Ticket {
protected:
    long ticketNummer;
    time_t datum = time(nullptr);
    std::shared_ptr<Medewerker> melder;
    std::shared_ptr<Helpdeskmedewerker> oplosser = nullptr;
    std::string probleemBeschrijving;
    std::string oplossingBeschrijving;

public:
    ~Ticket() = default;
    virtual void output() const = 0;
    void common_output() const;
    std::string getStatus() const;
};


#endif //TOETS_TICKET_H
