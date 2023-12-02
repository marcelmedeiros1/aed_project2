#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <utility>

class Airport
{
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    std::pair<float, float> position;

public:
    Airport(const std::string &code, const std::string &name, const std::string &city,
            const std::string &country, const std::pair<float, float> &position);
    Airport(const std::string &code);

    std::string getCode() const;
    void setCode(const std::string &c);

    std::string getName() const;
    void setName(const std::string &n);

    std::string getCity() const;
    void setCity(const std::string &c);

    std::string getCountry() const;
    void setCountry(const std::string &c);

    std::pair<float, float> getPosition() const;
    void setPosition(const std::pair<float, float> &pos);

    bool operator==(const Airport &other);
};

#endif
