#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

// g++ -o cityCriteriaTest cityCriteriaTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testCityCriteria()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    for(Airport a : flightnetwork.cityCriteria("New York")){
        cerr << a.getName() << endl;
    }

    if(flightnetwork.cityCriteria("New York").size() == 0)
        throw std::runtime_error("Test failed");

}


int main()
{
    try
    {
        testCityCriteria();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}