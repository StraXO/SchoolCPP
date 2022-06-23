//
// Created by Thomas Holtkamp on 6/16/2022.
//

#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2, double width) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->width = width;
}

void Line::OutputSVG(std::ostream &output) const {
    output << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << R"(" stroke="black" stroke-width=")" << width << "\" />";
}
