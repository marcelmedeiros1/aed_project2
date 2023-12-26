#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline
{
    std::string code;
    std::string name;
    std::string callsign;
    std::string country;

public:
    Airline(const std::string code, const std::string name, const std::string callsign, const std::string country);
    Airline(const std::string &code);

    std::string getCode() const;
    void setCode(const std::string &c);

    std::string getName() const;
    void setName(const std::string &n);

    std::string getCallsign() const;
    void setCallsign(const std::string &c);

    std::string getCountry() const;
    void setCountry(const std::string &c);
};

#endif
