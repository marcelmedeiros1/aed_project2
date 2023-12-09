#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

// g++ -o getDestinations getDestinations.cpp ../src/Airline.cpp ../src/Airport.cpp ../src/FlightNetwork.cpp

void testSmallAirport(FlightNetwork &flightnetwork)
{
    Airport airport("UAK");
    std::set<std::string> airports = flightnetwork.getAirportsDestinations(airport);
    std::set<std::string> cities = flightnetwork.getCitiesDestinations(airport);
    std::set<std::string> countries = flightnetwork.getCountriesDestinations(airport);

    std::cout << "AIRPORTS DESTINATIONS:\n";
    for (const std::string &s : airports)
        std::cout << s << '\n';
    std::cout << '\n';
    std::cout << "CITIES DESTINATIONS:\n";
    for (const std::string &s : cities)
        std::cout << s << '\n';
    std::cout << '\n';
    std::cout << "COUNTRIES DESTINATIONS:\n";
    for (const std::string &s : countries)
        std::cout << s << '\n';
    std::cout << '\n';
}

void testBigAirport(FlightNetwork &flightnetwork)
{
    Airport airport("GRU");
    std::set<std::string> airports = flightnetwork.getAirportsDestinations(airport);
    std::set<std::string> cities = flightnetwork.getCitiesDestinations(airport);
    std::set<std::string> countries = flightnetwork.getCountriesDestinations(airport);

    std::cout << "AIRPORTS DESTINATIONS:\n";
    for (const std::string &s : airports)
        std::cout << s << '\n';
    std::cout << '\n';
    std::cout << "CITIES DESTINATIONS:\n";
    for (const std::string &s : cities)
        std::cout << s << '\n';
    std::cout << '\n';
    std::cout << "COUNTRIES DESTINATIONS:\n";
    for (const std::string &s : countries)
        std::cout << s << '\n';
    std::cout << '\n';
}

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    try
    {
        testSmallAirport(flightnetwork);
        // testBigAirport(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
