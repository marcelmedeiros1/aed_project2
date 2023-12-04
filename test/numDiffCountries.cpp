#include "../inc/FlightNetwork.hpp"
#include <iostream>

// g++ -o numDiffCountries numDiffCountries.cpp ../src/FlightNetwork.cpp ../src/Airport.cpp ../src/Airline.cpp

void testnumDiffCountriesAirport()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport airport("REC", "Guararapes Gilberto Freyre Intl", "Recife", "Brazil", std::make_pair(-8.126794, -34.923039));

    std::cout << flightnetwork.numDiffCountriesAirport(airport) << '\n';
}

void testnumDiffCountriesCity()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    std::cout << flightnetwork.numDiffCountriesCity("Recife") << '\n';
}

int main()
{
    try
    {
        //testnumDiffCountriesAirport();
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
