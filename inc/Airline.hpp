#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

/**
 * @brief Represents an airline with specific attributes such as code, name, callsign, and country.
 */
class Airline
{
    /** The airline code. */
    std::string code;

    /** The name of the airline. */
    std::string name;

    /** The callsign of the airline. */
    std::string callsign;

    /** The country associated with the airline. */
    std::string country;

public:
    /**
     * @brief Constructor for creating an Airline object with specified attributes.
     * @param code The airline code.
     * @param name The name of the airline.
     * @param callsign The callsign of the airline.
     * @param country The country associated with the airline.
     */
    Airline(const std::string code, const std::string name, const std::string callsign, const std::string country);

    /**
     * @brief Constructor for creating an Airline object with only the code specified.
     * @param code The airline code.
     */
    Airline(const std::string &code);

    /**
     * @brief Gets the airline code.
     * @return The airline code.
     */
    std::string getCode() const;

    /**
     * @brief Sets the airline code.
     * @param c The new airline code.
     */
    void setCode(const std::string &c);

    /**
     * @brief Gets the name of the airline.
     * @return The name of the airline.
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the airline.
     * @param n The new name of the airline.
     */
    void setName(const std::string &n);

    /**
     * @brief Gets the callsign of the airline.
     * @return The callsign of the airline.
     */
    std::string getCallsign() const;

    /**
     * @brief Sets the callsign of the airline.
     * @param c The new callsign of the airline.
     */
    void setCallsign(const std::string &c);

    /**
     * @brief Gets the country associated with the airline.
     * @return The country associated with the airline.
     */
    std::string getCountry() const;

    /**
     * @brief Sets the country associated with the airline.
     * @param c The new country associated with the airline.
     */
    void setCountry(const std::string &c);
};

#endif
