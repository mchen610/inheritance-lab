#define PI 3.14159f
#include <math.h>
#include "Shapes.h"
#include <iostream>

void Shape2D::ShowArea() const
{
    std::cout << "The area of the " << GetName2D() << " is : " << Area() << '\n';
}

void Shape3D::ShowVolume() const
{
    std::cout << "The volume of the " << GetName3D() << " is : " << Volume() << '\n';
}

bool Shape2D::operator>(const Shape2D &rhs) const
{
    return Area() > rhs.Area();
}
bool Shape2D::operator<(const Shape2D &rhs) const
{
    return Area() < rhs.Area();
}
bool Shape2D::operator==(const Shape2D &rhs) const
{
    return Area() == rhs.Area();
}

bool Shape3D::operator>(const Shape3D &rhs) const
{
    return Volume() > rhs.Volume();
}
bool Shape3D::operator<(const Shape3D &rhs) const
{
    return Volume() < rhs.Volume();
}
bool Shape3D::operator==(const Shape3D &rhs) const
{
    return Volume() == rhs.Volume();
}

Circle::Circle(float radius) : radius(radius) {}

float Circle::Area() const
{
    return PI * std::pow(radius, 2);
}
std::string Circle::GetName2D() const
{
    return "Circle";
}
void Circle::Scale(float scaleFactor)
{
    radius = scaleFactor * radius;
}
void Circle::Display() const
{
    ShowArea();
    std::cout << "Radius: " << radius << '\n';
}
float Circle::getRadius() const
{
    return radius;
}

Square::Square(float length) : length(length) {}

float Square::Area() const
{
    return std::pow(length, 2);
}
std::string Square::GetName2D() const
{
    return "Square";
}
void Square::Scale(float scaleFactor)
{
    length = scaleFactor * length;
}
void Square::Display() const
{
    ShowArea();
    std::cout << "Length of a side: " << length << '\n';
}

Triangle::Triangle(float base, float height) : height(height), base(base) {}

float Triangle::Area() const
{
    return base * height / 2;
}
std::string Triangle::GetName2D() const
{
    return "Triangle";
}
void Triangle::Scale(float scaleFactor)
{
    base = scaleFactor * base;
    height = scaleFactor * height;
}
void Triangle::Display() const
{
    ShowArea();
    std::cout << "Base: " << base << '\n';
    std::cout << "Height: " << height << '\n';
}

TriangularPyramid::TriangularPyramid(float height, float baseLength, float baseHeight)
{
    triangle = Triangle(baseLength, baseHeight);
    this->height = height;
}

float TriangularPyramid::Volume() const
{
    return triangle.Area() * height / 3;
}

std::string TriangularPyramid::GetName3D() const
{
    return "TriangularPyramid";
}

void TriangularPyramid::Scale(float scaleFactor)
{
    triangle.Scale(scaleFactor);
    height = height * scaleFactor;
}

void TriangularPyramid::Display() const
{
    ShowVolume();
    std::cout << "The height is: " << height << '\n';
    triangle.Display();
}

Cylinder::Cylinder(float height, float radius)
{
    circle = Circle(radius);
    this->height = height;
}
float Cylinder::Volume() const
{
    return circle.Area() * height;
}
std::string Cylinder::GetName3D() const
{
    return "Cylinder";
}

void Cylinder::Scale(float scaleFactor)
{
    circle.Scale(scaleFactor);
    height = height * scaleFactor;
}

void Cylinder::Display() const
{
    ShowVolume();
    std::cout << "The height is: " << height << '\n';
    circle.Display();
}

Sphere::Sphere(float radius)
{
    circle = Circle(radius);
}

float Sphere::Volume() const
{
    return std::pow(circle.getRadius(), 3) * PI * 4 / 3;
}
std::string Sphere::GetName3D() const
{
    return "Sphere";
}

void Sphere::Scale(float scaleFactor)
{
    circle.Scale(scaleFactor);
}

void Sphere::Display() const
{
    ShowVolume();
    circle.Display();
}