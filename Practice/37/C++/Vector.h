#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const auto PI = 3.141592653589793;

class Vector {
private:
    Point begin, end;
public:
    Vector()
    {
        this->begin = Point(0, 0);
        this->end = Point(0, 1);
    }
    Vector(Point end)
    {
        this->begin = Point(0, 0);
        this->end = end;
    }
    Vector(Point begin, Point end)
    {
        this->begin = begin;
        this->end = end;
    }
    bool operator==(Vector p2)
    {
        if ((this->end.get_x() - this->begin.get_x() == p2.end.get_x() - p2.begin.get_x()) &&
            (this->end.get_y() - this->begin.get_y() == p2.end.get_y() - p2.begin.get_y()))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    Vector operator-()
    {
        return Vector(this->end, this->begin);
    }
    Vector operator+(Vector p2)
    {
        Point newVectorBegin(this->begin.get_x() + p2.begin.get_x(), this->begin.get_y() + p2.begin.get_y());
        Point newVectorEnd(this->end.get_x() + p2.end.get_x(), this->end.get_y() + p2.end.get_y());
        return Vector(newVectorBegin, newVectorEnd);
    }
    Vector operator-(Vector p2)
    {
        Point newVectorBegin(this->begin.get_x() - p2.begin.get_x(), this->begin.get_y() - p2.begin.get_y());
        Point newVectorEnd(this->end.get_x() - p2.end.get_x(), this->end.get_y() - p2.end.get_y());
        return Vector(newVectorBegin, newVectorEnd);
    }
    Vector operator*(double k)
    {
        Point newVectorBegin(this->begin.get_x() * k, this->begin.get_y() * k);
        Point newVectorEnd(this->end.get_x() * k, this->end.get_y() * k);
        return Vector(newVectorBegin, newVectorEnd);
    }
    double length()
    {
        return  sqrt(pow((this->end.get_x() - this->begin.get_x()), 2) + pow((this->end.get_y() - this->begin.get_y()), 2));
    }
    double operator*(Vector p2)
    {
        double xx, yy;
        xx = (this->end.get_x() - this->begin.get_x()) * (p2.end.get_x() - p2.begin.get_x());
        yy = (this->end.get_y() - this->begin.get_y()) * (p2.end.get_y() - p2.begin.get_y());
        return xx + yy;
    }

};