//
// Created by Thomas Holtkamp on 6/27/2022.
//

#include "Employee.h"

#include <utility>
#include <iostream>

Employee::Employee(std::string name, std::string password, std::string department) : name(std::move(name)), password(std::move(password)), department(std::move(department)) {}

const std::string &Employee::getName() const {
    return name;
}

void Employee::setName(const std::string &name) {
    Employee::name = name;
}

const std::string &Employee::getPassword() const {
    return password;
}

void Employee::setPassword(const std::string &password) {
    Employee::password = password;
}

const std::string &Employee::getDepartment() const {
    return department;
}

void Employee::setDepartment(const std::string &department) {
    Employee::department = department;
}

void Employee::output() const {
    std::cout << "\t" << getName() << " (" << getDepartment() << ")";
}
