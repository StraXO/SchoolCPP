//
// Created by Thomas Holtkamp on 6/23/2022.
//

#include "Helpdeskmedewerker.h"

#include <utility>

Helpdeskmedewerker::Helpdeskmedewerker(std::string naam, std::string wachtwoord, std::string afdeling, std::string expertise) : Medewerker(std::move(naam), wachtwoord, afdeling) {
    this->expertise = std::move(expertise);
}

std::string Helpdeskmedewerker::getExpertise() {
    return this->expertise;
}