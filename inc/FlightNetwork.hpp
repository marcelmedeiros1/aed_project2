#ifndef FLIGHT_NETWORK_H
#define FLIGHT_NETWORK_H

#include "Graph.hpp"
#include "Airport.hpp"
#include "Airline.hpp"
#include <fstream>
#include <sstream>
#include <cmath>

class FlightNetwork
{
    Graph<Airport> airportsGraph;

public:
    FlightNetwork(const std::string &airlines_filename, const std::string &airports_filename, const std::string &flights_filename);

    int getGlobalNumOfAirports() const;
    int getGlobalNumOfFlights() const;
    std::pair<int,int> numFlights(Airport &airport);
    Graph<Airport> getAiportsGraph();
};

#endif
