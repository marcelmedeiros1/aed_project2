#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <string>

using namespace std;

// g++ -o numFlightsAirlineTest numFlightsAirlineTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testNumFlightsCity()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airline airline("NMB","Air Namibia","NAMIBIA","Namibia");
    int res = flightnetwork.numFlightsAirline(airline);

    cout << res << endl;
}

int main()
{
    try
    {
        testNumFlightsCity();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
