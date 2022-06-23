//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_HELPDESKMEDEWERKER_H
#define TOETS_HELPDESKMEDEWERKER_H


#include <string>
#include "Medewerker.h"

class Helpdeskmedewerker : public Medewerker {
private:
    std::string expertise;

public:
    Helpdeskmedewerker(std::string naam, std::string wachtwoord, std::string afdeling, std::string expertise);
    ~Helpdeskmedewerker() = default;
    std::string getExpertise();
};


#endif //TOETS_HELPDESKMEDEWERKER_H
