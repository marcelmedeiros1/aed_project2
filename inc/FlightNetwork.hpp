#ifndef FLIGHT_NETWORK_H
#define FLIGHT_NETWORK_H

#include "Graph.hpp"
#include "Airport.hpp"
#include "Airline.hpp"
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>

class FlightNetwork
{
    Graph<Airport> airportsGraph;

public:
    FlightNetwork(const std::string &airlines_filename, const std::string &airports_filename, const std::string &flights_filename);
    Graph<Airport> getAiportsGraph();

    int getGlobalNumOfAirports() const;
    int getGlobalNumOfFlights() const;
    std::pair<int, int> numFlightsAirport(const Airport &airport);
    int numFlightsCity(const std::string &city) const;
    int numFlightsAirline(Airline &airline) const;
    std::set<std::string> getDiffCountriesAirport(const Airport &airport) const;
    std::set<std::string> getDiffCountriesCity(const std::string &city) const;
};

#endif
