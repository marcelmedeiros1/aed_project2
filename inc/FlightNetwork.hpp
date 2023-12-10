#ifndef FLIGHT_NETWORK_H
#define FLIGHT_NETWORK_H

#include "Graph.hpp"
#include "Airport.hpp"
#include "Airline.hpp"
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>
#include <tuple>

class FlightNetwork
{
    Graph<Airport> airportsGraph;

public:
    FlightNetwork(const std::string &airlines_filename, const std::string &airports_filename, const std::string &flights_filename);
    Graph<Airport> getAiportsGraph();

    int getGlobalNumOfAirports() const;                                                       // 3) i.
    int getGlobalNumOfFlights() const;                                                        // 3) i.
    std::pair<int, int> numFlightsAirport(const Airport &airport);                            // 3) ii.
    int numFlightsCity(const std::string &city) const;                                        // 3) iii.
    int numFlightsAirline(Airline &airline) const;                                            // 3) iii.
    std::set<std::string> getDiffCountriesAirport(const Airport &airport) const;              // 3) iv.
    std::set<std::string> getDiffCountriesCity(const std::string &city) const;                // 3) iv.
    std::set<std::string> getAirportsDestinations(const Airport &airport) const;              // 3) v.
    std::set<std::string> getCitiesDestinations(const Airport &airport) const;                // 3) v.
    std::set<std::string> getCountriesDestinations(const Airport &airport) const;             // 3) v.
    std::set<std::string> getReachableAirports(const Airport &airport, const int &distance);  // 3) vi.
    std::set<std::string> getReachableCities(const Airport &airport, const int &distance);    // 3) vi.
    std::set<std::string> getReachableCountries(const Airport &airport, const int &distance); // 3) vi.
    int maximumTrip(std::vector<std::pair<std::string,std::string>>& airports);               // 3) vii.

};

#endif
