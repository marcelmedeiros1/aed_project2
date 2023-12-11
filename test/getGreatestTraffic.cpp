#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

// g++ -o getGreatestTraffic getGreatestTraffic.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp
using namespace std;
void testGetGreatestTraffic()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    
    set<string> res = flightnetwork.getGreatestTraffic(10);
    for(auto a : res){
        cout << a << endl;
    }
}

int main()
{
    try
    {
        testGetGreatestTraffic();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}