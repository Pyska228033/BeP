#include "Circle.h"
#include "FIGURE.h"

Circle::Circle(double r)
{
    radius = r;
}

Circle::Circle()
{

}

double Circle::getSquare() override
    {
        return radius * radius * 3.14;
    }

double Circle::getPerimeter()override
    {
        return 2 * 3.14 * radius;
    }

Circle* Circle::NOVA() override
    {
        Circle* a = new Circle;
        
        a -> radius = radius * radius;
        return a;
    }

void Circle::showFigureType()
    {
        cout << "Circle" << endl;
    }