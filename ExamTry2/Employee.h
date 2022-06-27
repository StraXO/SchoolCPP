//
// Created by Thomas Holtkamp on 6/27/2022.
//

#ifndef TOETS_EMPLOYEE_H
#define TOETS_EMPLOYEE_H


#include <string>

class Employee {
    std::string name, password, department;

public:
    Employee(std::string name, std::string password, std::string department);
    virtual ~Employee() = default;

    virtual void output() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    const std::string &getDepartment() const;

    void setDepartment(const std::string &department);
};


#endif //TOETS_EMPLOYEE_H
