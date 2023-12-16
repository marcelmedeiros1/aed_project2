#include "../inc/FlightNetwork.hpp"
#include <iostream>



void testEssentialAirports()
{
    FlightNetwork flightnetwork("airlines_test.csv", "airports_test.csv", "flights_test.csv");

    std::set<std::string> res = flightnetwork.getEssentialAirports();

    std::cout << "ARTICULATION POINTS:" << '\n';
    for (const std::string &s : res)
    {
        std::cout << s << '\n';
    }
    std::cout << '\n';
}

void realEssentialAirports()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    std::set<std::string> res = flightnetwork.getEssentialAirports();

    std::cout << "ARTICULATION POINTS:" << '\n';
    for (const std::string &s : res)
    {
        std::cout << s << '\n';
    }
    std::cout << '\n';
}

int main()
{
    try
    {
        testEssentialAirports();
        //realEssentialAirports();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
