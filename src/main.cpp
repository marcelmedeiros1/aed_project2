#include "../inc/Airline.hpp"
#include "../inc/Airport.hpp"
#include "../inc/Graph.hpp"
#include "../inc/FlightNetwork.hpp"
#include "../inc/App.hpp"

// g++ -o main main.cpp Airline.cpp Airport.cpp App.cpp FlightNetwork.cpp

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    App app(flightnetwork);
    return 0;
}
