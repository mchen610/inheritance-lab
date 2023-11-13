#pragma once
#include <string>

class Shape
{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
};

class Shape2D : virtual public Shape
{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual std::string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Square : public Shape2D
{
private:
    float length;

public:
    Square(float length = 0);
    float Area() const;
    std::string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Triangle : public Shape2D
{
private:
    float base;
    float height;

public:
    Triangle(float base = 0, float height = 0);
    float Area() const;
    std::string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Circle : public Shape2D
{
private:
    float radius;

public:
    Circle(float radius = 0);
    float Area() const;
    std::string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;
    float getRadius() const;
};

class Shape3D : virtual public Shape
{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual std::string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};

class TriangularPyramid : public Shape3D, private Triangle
{
private:
    Triangle triangle;
    float height;

public:
    TriangularPyramid(float height = 0, float baseLength = 0, float baseHeight = 0);
    float Volume() const;
    std::string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Cylinder : public Shape3D, private Circle
{
private:
    Circle circle;
    float height;

public:
    Cylinder(float height = 0, float radius = 0);
    float Volume() const;
    std::string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Sphere : public Shape3D, private Circle
{
private:
    Circle circle;

public:
    Sphere(float radius = 0);
    float Volume() const;
    std::string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;
};
