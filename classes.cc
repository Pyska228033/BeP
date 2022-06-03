#include <iostream>
#include "Circle.h"
#include "FIGURE.h"
#include "Rectangle.h"


using namespace std;
 
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

Rectangle::Rectangle()
    {
        
    }

Rectangle::Rectangle(double w, double h) 
    {
        width = w;
        height = h;
    }

double Rectangle::getSquare() override
    {
        return width * height;
    }

double Rectangle::getPerimeter() override
    {
        return width * 2 + height * 2;
    }

Rectangle* Rectangle::NOVA() override
    {
        Rectangle* a = new Rectangle();
        a -> width = width * width;
        return a;
    }

void Rectangle::showFigureType()
    {
        cout << "Rectangle" << endl;
    }   

int main()
{
    Rectangle rect = Rectangle(30,50);
    Circle circle = Circle(30);
    
    Rectangle f = Rectangle(100,50);
    Rectangle* a = f.NOVA();
    
    cout << "Rectangle square: " << rect.getSquare() << endl;
    cout << "Circle square: " << circle.getSquare() << endl;
    cout << "NOVA: " << f.width << endl;
    cout << "NOVA: " << a -> width << endl;
    return 0;
}