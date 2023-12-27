#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <utility>

/**
 * @brief Represents an airport with attributes such as code, name, city, country, and position.
 */
class Airport
{
    /** The airport code. */
    std::string code;

    /** The name of the airport. */
    std::string name;

    /** The city where the airport is located. */
    std::string city;

    /** The country where the airport is located. */
    std::string country;

    /** The geographical position of the airport (latitude, longitude). */
    std::pair<float, float> position;

public:
    /**
     * @brief Constructor for creating an Airport object with specified attributes.
     * @param code The airport code.
     * @param name The name of the airport.
     * @param city The city where the airport is located.
     * @param country The country where the airport is located.
     * @param position The geographical position of the airport (latitude, longitude).
     */
    Airport(const std::string &code, const std::string &name, const std::string &city,
            const std::string &country, const std::pair<float, float> &position);

    /**
     * @brief Constructor for creating an Airport object with only the code specified.
     * @param code The airport code.
     */
    Airport(const std::string &code);

    /**
     * @brief Gets the airport code.
     * @return The airport code.
     */
    std::string getCode() const;

    /**
     * @brief Sets the airport code.
     * @param c The new airport code.
     */
    void setCode(const std::string &c);

    /**
     * @brief Gets the name of the airport.
     * @return The name of the airport.
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the airport.
     * @param n The new name of the airport.
     */
    void setName(const std::string &n);

    /**
     * @brief Gets the city where the airport is located.
     * @return The city where the airport is located.
     */
    std::string getCity() const;

    /**
     * @brief Sets the city where the airport is located.
     * @param c The new city where the airport is located.
     */
    void setCity(const std::string &c);

    /**
     * @brief Gets the country where the airport is located.
     * @return The country where the airport is located.
     */
    std::string getCountry() const;

    /**
     * @brief Sets the country where the airport is located.
     * @param c The new country where the airport is located.
     */
    void setCountry(const std::string &c);

    /**
     * @brief Gets the geographical position of the airport.
     * @return The geographical position of the airport (latitude, longitude).
     */
    std::pair<float, float> getPosition() const;

    /**
     * @brief Sets the geographical position of the airport.
     * @param pos The new geographical position of the airport (latitude, longitude).
     */
    void setPosition(const std::pair<float, float> &pos);

    /**
     * @brief Overloaded equality operator to compare airports based on their codes.
     * @param other The other airport to compare.
     * @return True if the airports have the same code, false otherwise.
     */
    bool operator==(const Airport &other);

    /**
     * @brief Overloaded less-than operator to compare airports based on their codes.
     * @param other The other airport to compare.
     * @return True if the code of this airport is less than the code of the other airport.
     */
    bool operator<(const Airport &other);
};

#endif
