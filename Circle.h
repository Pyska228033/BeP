#include <iostream>
#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : public Figure
{
public:
    double radius;
    
public:

    Circle(double r);
    
    Circle();
    
    double getSquare() override;
    
    double getPerimeter() override;
    
    Circle* NOVA() override;
    
    void showFigureType();
};
#endif