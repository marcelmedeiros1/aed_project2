#ifndef FLIGHT_NETWORK_H
#define FLIGHT_NETWORK_H

#include "Airline.hpp"
#include "Airport.hpp"
#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <tuple>
#include <functional>


class FlightNetwork
{
    Graph<Airport> airportsGraph;

public:
    FlightNetwork();
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
    int maximumTrip(std::vector<std::pair<std::string, std::string>> &airports);              // 3) vii.
    std::set<std::string> getGreatestTraffic(const int &k);                                   // 3) viii.
    std::set<std::string> getEssentialAirports();                                             // 3) ix.

    Airport codeCriteria(const std::string &code) const;                                                     // 4) i.
    Airport nameCriteria(const std::string &name) const;                                                     // 4) i.
    std::vector<Airport> cityCriteria(const std::string &city) const;                                        // 4) ii.
    std::vector<Airport> coordinateCriteria(const float &lat, const float &lon) const; // 4) iii.
    std::vector<vector<Airport>> bestFlight(const Airport &source, const Airport &destination, const set<string> &allowedAirlines={}, bool minimizeAirlines=false) const; // 4)
    std::vector<std::vector<Airport>> listBestFlights(const int &flag1, const int &flag2,const set<string> &allowedAirlines, bool minimizeAirlines) const;
    bool isPathValid(const vector<Airport> &path, const set<string> &allowedAirlines, bool minimizeAirlines) const;
    std::vector<vector<Airport>> bestFlightFiltered(const Airport &source, const Airport &destination, const set<string> &allowedAirlines, bool minimizeAirlines) const;
};

void dfs_art(Graph<Airport> &g, Vertex<Airport> *v, set<string> &l, int &i);
double haversineDistance(double lat1, double lon1, double lat2, double lon2);
std::string airlineCodeToName(const std::string &code);

#endif
