#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

//g++ -o numFlightsTest numFlightsTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp
void testNumFlights(){
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    Airport airport("LAE","Nadzab","Nadzab","Papua New Guinea",{-6.569828,146.726242});
    pair<int,int> res = flightnetwork.numFlights(airport);
    
    if(res.first == 11 && res.second == 2) return;
        std::cerr << "Error: FlightNework.numFlights();" << std::endl;
        throw std::runtime_error("Test failed");
}

int main(){
try
    {
        testNumFlights();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}