#include "../inc/Airport.hpp"
using namespace std;

Airport::Airport(const string &code, const string &name, const string &city,
                 const string &country, const pair<float, float> &position)
    : code(code), name(name), city(city), country(country), position(position) {}

string Airport::getCode() const
{
    return code;
}

void Airport::setCode(const string &c)
{
    code = c;
}

string Airport::getName() const
{
    return name;
}

void Airport::setName(const string &n)
{
    name = n;
}

string Airport::getCity() const
{
    return city;
}

void Airport::setCity(const string &c)
{
    city = c;
}

string Airport::getCountry() const
{
    return country;
}

void Airport::setCountry(const string &c)
{
    country = c;
}

pair<float, float> Airport::getPosition() const
{
    return position;
}

void Airport::setPosition(const pair<float, float> &pos)
{
    position = pos;
}
