//
// Created by Thomas Holtkamp on 6/23/2022.
//

#ifndef TOETS_MEDEWERKER_H
#define TOETS_MEDEWERKER_H


#include <string>

class Medewerker {
private:
    std::string naam, wachtwoord, afdeling;

public:
    Medewerker(std::string naam, std::string wachtwoord, std::string afdeling);
    ~Medewerker() = default;
    std::string getNaam();
    std::string getAfdeling();
};


#endif //TOETS_MEDEWERKER_H
