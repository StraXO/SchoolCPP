//
// Created by Thomas Holtkamp on 6/23/2022.
//

#include "Medewerker.h"

Medewerker::Medewerker(std::string naam, std::string wachtwoord, std::string afdeling) {
    this->naam = naam;
    this->wachtwoord = wachtwoord;
    this->afdeling = afdeling;
}

std::string Medewerker::getNaam() {
    return this->naam;
}

std::string Medewerker::getAfdeling() {
    return this->afdeling;
}
