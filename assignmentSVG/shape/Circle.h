//
// Created by Thomas Holtkamp on 6/16/2022.
//

#ifndef ASSIGNMENTSVG_CIRCLE_H
#define ASSIGNMENTSVG_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
    double x, y, radius;

public:
    Circle(double x, double y, double radius);

    void OutputSVG(std::ostream &output) const override;
};


#endif //ASSIGNMENTSVG_CIRCLE_H
