#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

// g++ -o flightNetworkTest flightNetworkTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testNumOfAirports()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    if (flightnetwork.getGlobalNumOfAirports() != 3019)
    {
        std::cerr << "Error: getGlobalNumOfAirports()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testTotalNumOfFlights()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    if (flightnetwork.getGlobalNumOfFlights() != 63832)
    {
        std::cerr << "Error: getGlobalNumOfFlights()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

int main()
{
    try
    {
        testNumOfAirports();
        testTotalNumOfFlights();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
