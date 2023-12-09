#include "../inc/FlightNetwork.hpp"
#include <iostream>

//

void testReachableAirports(FlightNetwork &flightnetwork)
{
    Airport airport("UAK");
    std::set<std::string> res = flightnetwork.getReachableAirports(airport, 2);

    std::cout << "REACHABLE AIRPORTS:\n";
    for (const std::string s : res)
        std::cout << s << '\n';
    std::cout << '\n';
}

void testReachableCities(FlightNetwork &flightnetwork)
{
    Airport airport("UAK");
    std::set<std::string> res = flightnetwork.getReachableCities(airport, 2);

    std::cout << "REACHABLE CITIES:\n";
    for (const std::string s : res)
        std::cout << s << '\n';
    std::cout << '\n';
}

void testReachableCountries(FlightNetwork &flightnetwork)
{
    Airport airport("UAK");
    std::set<std::string> res = flightnetwork.getReachableCountries(airport, 2);

    std::cout << "REACHABLE COUNTRIES:\n";
    for (const std::string s : res)
        std::cout << s << '\n';
    std::cout << '\n';
}

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    try
    {
        testReachableAirports(flightnetwork);
        testReachableCities(flightnetwork);
        testReachableCountries(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
