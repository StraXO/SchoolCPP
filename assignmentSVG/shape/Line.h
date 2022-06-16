//
// Created by Thomas Holtkamp on 6/16/2022.
//

#ifndef ASSIGNMENTSVG_LINE_H
#define ASSIGNMENTSVG_LINE_H


#include "Shape.h"

class Line : public Shape {
    double x1, y1, x2, y2, width;

public:
    Line(double x1, double y1, double x2, double y2, double width);

    void OutputSVG(std::ostream &output) const override;
    virtual std::vector<std::shared_ptr<Shape>> LoadFigure(std::string const &filename) const override;
};


#endif //ASSIGNMENTSVG_LINE_H
