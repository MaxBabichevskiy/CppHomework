#include <iostream>
using namespace std;

class Flat
{
private:
    double price;
    double area;
public:
    Flat() : price(0), area(0) { };
    Flat(const double& prc, const double& area) : price(prc), area(area) { };
    Flat(const Flat& date) : price(date.price), area(date.area) { };
    ~Flat() { };
    Flat& operator = (const Flat& date);

    friend bool operator == (const Flat& lhs, const Flat& rhs);
    friend bool operator != (const Flat& lhs, const Flat& rhs);

    friend bool operator > (const Flat& lhs, const Flat& rhs);
    friend bool operator < (const Flat& lhs, const Flat& rhs);
};

Flat& Flat::operator = (const Flat& date)
{
    if (this == &date)
    {
        return *this;
    }

    price = date.price;
    area = date.area;
    return *this;
}

bool operator == (const Flat& lhs, const Flat& rhs)
{
    return lhs.area == rhs.area;
}

bool operator != (const Flat& lhs, const Flat& rhs)
{
    return !(lhs.area == rhs.area);
}

bool operator > (const Flat& lhs, const Flat& rhs)
{
    return lhs.price > rhs.price;
}

bool operator < (const Flat& lhs, const Flat& rhs)
{
    return lhs.price < rhs.price;
}

void main() {



}