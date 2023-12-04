#include "../inc/FlightNetwork.hpp"
#include <iostream>

// g++ -o getDiffCountries getDiffCountries.cpp ../src/FlightNetwork.cpp ../src/Airport.cpp ../src/Airline.cpp

void testnumDiffCountriesAirport()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport airport("REC", "Guararapes Gilberto Freyre Intl", "Recife", "Brazil", std::make_pair(-8.126794, -34.923039));

    if (flightnetwork.getDiffCountriesAirport(airport).size() != 5)
    {
        std::cerr << "Error: testnumDiffCountriesAirport()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testnumDiffCountriesCity()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    if (flightnetwork.getDiffCountriesCity("Recife").size() != 5)
    {
        std::cerr << "Error: testnumDiffCountriesCity()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

int main()
{
    try
    {
        testnumDiffCountriesAirport();
        testnumDiffCountriesCity();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
