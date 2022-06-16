//
// Created by Thomas Holtkamp on 6/16/2022.
//

#ifndef ASSIGNMENTSVG_SHAPE_H
#define ASSIGNMENTSVG_SHAPE_H

#include <vector>
#include <memory>
#include "Line.h"

class FigureCount {
public:
    unsigned int circleCount = 0;
    unsigned int lineCount = 0;
};

class Shape {
public:
    virtual void OutputSVG(std::ostream &output) const = 0;
    virtual std::vector<std::shared_ptr<Shape>> LoadFigure(std::string const &filename) const = 0;

protected:
    Shape() = default;
    virtual ~Shape() = default;
};


#endif //ASSIGNMENTSVG_SHAPE_H
