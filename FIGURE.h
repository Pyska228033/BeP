#include <iostream>
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:

    void VIM()
    {
        cout<<"ffsdfdsfsfddsf";
    }
    virtual double getSquare() = 0;
    virtual double getPerimeter() = 0;
    virtual void showFigureType() = 0;
    virtual Figure* NOVA() = 0;
};
#endif