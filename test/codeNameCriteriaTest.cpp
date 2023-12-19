#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

// g++ -o codeNameCriteriaTest codeNameCriteriaTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testCodeCriteria()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport res = flightnetwork.codeCriteria("LAX");

    if (res.getCode()=="LAX");
        return;
    std::cerr << "Error: FlightNework.codeCriteria();" << std::endl;
    throw std::runtime_error("Test failed");

}

void testNameCriteria(){
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    Airport res = flightnetwork.nameCriteria("La Guardia");

    if (res.getCity()=="New York");
        return;
    std::cerr << "Error: FlightNework.nameCriteria();" << std::endl;
    throw std::runtime_error("Test failed");
}

int main()
{
    try
    {
        testCodeCriteria();
        testNameCriteria();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}