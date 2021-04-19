#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>


enum class coord_system
{
    Cartesian,
    Polar
};

bool aresame(const double q, const double w, int accuracy_signs = 10)
{
    return !int(abs(q - w) * pow(10, accuracy_signs));
}

class Point
{
private:
    double x, y;
    coord_system system;
public:
    Point()
    {
        this->x = 0;
        this->y = 0;
        this->system = coord_system::Cartesian;
    }
    Point(double a1, double a2, coord_system system = coord_system::Cartesian)
    {
        this->x = a1;
        this->y = a2;
        this->system = system;
    }
    double get_x()
    {
        if (this->system == coord_system::Cartesian)
        {
            return x;
        }
        else
        {
            return x * cos(y);
        }
    }
    double get_y()
    {
        if (this->system == coord_system::Cartesian)
        {
            return y;
        }
        else
        {
            return x * sin(y);
        }
    }
    double get_r()
    {
        if (this->system == coord_system::Cartesian)
        {
            return sqrt(pow(x, 2) + pow(y, 2));
        }
        else
        {
            return x;
        }
    }
    double get_phi()
    {
        if (this->system == coord_system::Cartesian)
        {
            return acos(x / (sqrt(pow(x, 2) + pow(y, 2))));
        }
        else
        {
            return y;
        }
    }
    void set_x(double x)
    {
        if (this->system == coord_system::Cartesian)
        {
            this->x = x;
        }
        else
        {
            double r = sqrt(x * x + this->get_y() * this->get_y());
            double phi = atan(this->get_y() / x);
            this->x = r;
            this->y = phi;
        }
    }
    void set_y(double y)
    {
        if (this->system == coord_system::Cartesian)
        {
            this->y = y;
        }
        else
        {
            double r = sqrt(y * y + this->get_x() * this->get_x());
            double phi = atan(this->get_x() / y);
            this->x = r;
            this->y = phi;
        }
    }
    void set_r(double r)
    {
        if (this->system == coord_system::Cartesian)
        {
            double x = r * cos(this->get_phi());
            double y = r * sin(this->get_phi());
            this->x = x;
            this->y = y;
        }
        else
        {
            this->x = r;
        }
    }
    void set_phi(double phi)
    {
        if (this->system == coord_system::Cartesian)
        {
            double x = this->get_r() * cos(phi);
            double y = this->get_r() * sin(phi);
            this->x = x;
            this->y = y;
        }
        else
        {
            this->y = phi;
        }
    }
    bool operator==(Point p2)
    {

        return aresame(this->get_r(), p2.get_r()) && aresame(this->get_phi(), p2.get_phi());
    };
    bool operator!=(Point p2)
    {
        return *this != p2;
    };

    friend std::ostream& operator<<(std::ostream& sout, Point& point)
    {
        sout << "(" << point.get_x() << "," << point.get_y() << "), ";
        return sout;
    }
    friend std::istream& operator>> (std::istream& input_stream, Point& point)
    {
        std::string temp;
        input_stream >> temp;
        if (temp[0] == '(') {
            temp = temp.substr(1);
        }

        auto endPointer = temp.find(')');
        temp = temp.substr(0, endPointer);
        auto x = temp.substr(0, temp.find(','));
        auto y = temp.substr(temp.find(',') + 1);

        point.x = std::stod(x);
        point.y = std::stod(y);

        return input_stream;
    }
};
