#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

void testSmallAirport()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport airport("UAK");
    std::tuple<std::set<std::string>, std::set<std::string>, std::set<std::string>> res = flightnetwork.getAirportDestinations(airport);

    std::cout << "AIRPORTS:\n";
    for (const std::string &air : std::get<0>(res))
        std::cout << air << '\n';
    std::cout << "\nCITIES:\n";
    for (const std::string &c : std::get<1>(res))
        std::cout << c << '\n';
    std::cout << "\nCOUNTRIES:\n";
    for (const std::string &c : std::get<2>(res))
        std::cout << c << '\n';
}

void testBigAirport()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport airport("GRU");
    std::tuple<std::set<std::string>, std::set<std::string>, std::set<std::string>> res = flightnetwork.getAirportDestinations(airport);

    std::cout << "AIRPORTS:\n";
    for (const std::string &air : std::get<0>(res))
        std::cout << air << '\n';
    std::cout << "\nCITIES:\n";
    for (const std::string &c : std::get<1>(res))
        std::cout << c << '\n';
    std::cout << "\nCOUNTRIES:\n";
    for (const std::string &c : std::get<2>(res))
        std::cout << c << '\n';
}

int main()
{
    try
    {
        testSmallAirport();
        //testBigAirport();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
