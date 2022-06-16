//
// Created by Thomas Holtkamp on 6/16/2022.
//

#include "Circle.h"

Circle::Circle(double x, double y, double radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

void Circle::OutputSVG(std::ostream &output) const {
    output << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << radius << "\" stroke=\"black\" stroke-width=\"1\" fill=\"none\" />" << std::endl;
}