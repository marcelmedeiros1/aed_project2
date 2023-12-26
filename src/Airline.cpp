#include "../inc/Airline.hpp"
using namespace std;

Airline::Airline(const string code, const string name, const string callsign, const string country)
    : code(code), name(name), callsign(callsign), country(country){};

Airline::Airline(const string &code) : code(code) {}

string Airline::getCode() const
{
    return code;
}

string Airline::getName() const
{
    return name;
}

string Airline::getCallsign() const
{
    return callsign;
}

string Airline::getCountry() const
{
    return country;
}

void Airline::setCode(const string &c)
{
    code = c;
}

void Airline::setName(const string &n)
{
    name = n;
}

void Airline::setCallsign(const string &c)
{
    callsign = c;
}

void Airline::setCountry(const string &c)
{
    country = c;
}
