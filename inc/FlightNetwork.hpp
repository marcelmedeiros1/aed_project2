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
#include <limits>

/**
 * @brief Represents a flight network consisting of airports and flights.
 */
class FlightNetwork
{
    /**
     * @brief Graph representing the network of airports and flights.
     */
    Graph<Airport> airportsGraph;

public:
    /**
     * @brief Default constructor for the FlightNetwork class.\n
     * Time complexity: O(1).
     */
    FlightNetwork();

    /**
     * @brief Parameterized constructor for the FlightNetwork class.\n
     * Time complexity: O(V + E), where V is the number of lines in the airports.csv file and E is the number of lines in the flights.csv file.
     *
     * @param airlines_filename Filename for the airlines data.
     * @param airports_filename Filename for the airports data.
     * @param flights_filename Filename for the flights data.
     */
    FlightNetwork(const std::string &airlines_filename, const std::string &airports_filename, const std::string &flights_filename);

    /**
     * @brief Getter function to retrieve the airports graph.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @return Graph<Airport> representing the airports and flights.
     */
    Graph<Airport> getAiportsGraph();

    /**
     * @brief Get the total number of airports in the network.\n
     * Time complexity: O(1).
     *
     * @return Total number of airports.
     */
    int getGlobalNumOfAirports() const; // 3) i.

    /**
     * @brief Get the total number of flights in the network.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @return Total number of flights.
     */
    int getGlobalNumOfFlights() const; // 3) i.

    /**
     * @brief Get the number of flights departing or arriving at a specific airport.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The target airport.
     * @return A pair containing the total number of flights and the number of different airlines.
     */
    std::pair<int, int> numFlightsAirport(const Airport &airport); // 3) ii.

    /**
     * @brief Get the total number of flights departing or arriving in a specific city.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param city The target city.
     * @return Total number of flights.
     */
    int numFlightsCity(const std::string &city) const; // 3) iii.

    /**
     * @brief Get the total number of flights operated by a specific airline.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airline The target airline.
     * @return Total number of flights.
     */
    int numFlightsAirline(Airline &airline) const; // 3) iii.

    /**
     * @brief Get the set of different countries connected to a specific airport.\n
     * Time complexity: O(N * log(P)), where N is the size of the adjacency list and P is the size of the set.
     *
     * @param airport The target airport.
     * @return Set of countries.
     */
    std::set<std::string> getDiffCountriesAirport(const Airport &airport) const; // 3) iv.

    /**
     * @brief Get the set of different countries connected to airports in a specific city.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param city The target city.
     * @return Set of countries.
     */
    std::set<std::string> getDiffCountriesCity(const std::string &city) const; // 3) iv.

    /**
     * @brief Get the set of airport names connected to a specific airport.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The target airport.
     * @return Set of airport names.
     */
    std::set<std::string> getAirportsDestinations(const Airport &airport) const; // 3) v.

    /**
     * @brief Get the set of city names connected to a specific airport.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The target airport.
     * @return Set of city names.
     */
    std::set<std::string> getCitiesDestinations(const Airport &airport) const; // 3) v.

    /**
     * @brief Get the set of country names connected to a specific airport.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The target airport.
     * @return Set of country names.
     */
    std::set<std::string> getCountriesDestinations(const Airport &airport) const; // 3) v.

    /**
     * @brief Get the set of airport names reachable from a specific airport within a given distance.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The source airport.
     * @param distance The maximum distance to consider.
     * @return Set of reachable airport names.
     */
    std::set<std::string> getReachableAirports(const Airport &airport, const int &distance); // 3) vi.

    /**
     * @brief Get the set of city names reachable from a specific airport within a given distance.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The source airport.
     * @param distance The maximum distance to consider.
     * @return Set of reachable city names.
     */
    std::set<std::string> getReachableCities(const Airport &airport, const int &distance); // 3) vi.

    /**
     * @brief Get the set of country names reachable from a specific airport within a given distance.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airport The source airport.
     * @param distance The maximum distance to consider.
     * @return Set of reachable country names.
     */
    std::set<std::string> getReachableCountries(const Airport &airport, const int &distance); // 3) vi.

    /**
     * @brief Find the maximum number of stops for a round-trip connecting the given airports.\n
     * Time complexity: O(V + E), where V is the number of airports and E is the number of flights.
     *
     * @param airports A vector of pairs representing airport codes for the round-trip.
     * @return The maximum number of stops for the round-trip.
     */
    int maximumTrip(std::vector<std::pair<std::string, std::string>> &airports); // 3) vii.

    /**
     * @brief Get the set of airports with the greatest traffic, considering both incoming and outgoing flights.\n
     * Time complexity: O(V²*E), where V is the number of airports and E is the number of flights.
     *
     * @param k The number of airports to retrieve.
     * @return Set of airport names with the greatest traffic.
     */
    std::set<std::string> getGreatestTraffic(const int &k); // 3) viii.

    /**
     * @brief Perform a depth-first search to identify essential airports in the flight network.\n
     * Time complexity: O(V*(V+E)), where V is the number of airports and E is the number of flights.
     *
     * @return Set of essential airport names.
     */
    std::set<std::string> getEssentialAirports(); // 3) ix.

    /**
     * @brief Find an airport by its code.\n
     * Time Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param code The code of the target airport.
     * @return The airport matching the provided code.
     * @throw runtime_error if no airport is found with the given code.
     */
    Airport codeCriteria(const std::string &code) const; // 4) i.

    /**
     * @brief Find an airport by its name.\n
     * Time Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param name The name of the target airport.
     * @return The airport matching the provided name.
     * @throw runtime_error if no airport is found with the given name.
     */
    Airport nameCriteria(const std::string &name) const; // 4) i.

    /**
     * @brief Find airports in the specified city.\n
     * Time Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param city The name of the city to search for.
     * @return Vector of airports in the given city.
     * @throw runtime_error if no city with the provided name is found.
     */
    std::vector<Airport> cityCriteria(const std::string &city) const; // 4) ii.

    /**
     * @brief Find airports near the specified coordinates.\n
     * Time Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param lat The latitude of the target location.
     * @param lon The longitude of the target location.
     * @return Vector of airports near the specified coordinates.
     * @throw runtime_error if no airports are found in the specified area.
     */
    std::vector<Airport> coordinateCriteria(const float &lat, const float &lon) const; // 4) iii.

    /**
     * @brief Find the best flight paths between source and destination airports.\n
     * Time Complexity: O(V + E) where V is the number of vertices in the graph.
     *
     * @param source The source airport.
     * @param destination The destination airport.
     * @param allowedAirlines Set of allowed airlines (empty for any).
     * @param minimizeAirlines Flag to minimize the number of unique airlines in the path.
     * @return Vector of vector of airports representing the best flight paths.
     */
    std::vector<vector<Airport>> bestFlight(const Airport &source, const Airport &destination, const set<string> &allowedAirlines = {}, bool minimizeAirlines = false) const; // 4)

    /**
     * @brief List the best flights based on user input for source and destination.\n
     * Time Complexity: O(N * M * (V + E)) where V is the number of vertices in the graph, E is the number of flights, N and M is the number of origins and destinations.
     *
     * @param flag1 Type of input for the source (1: code, 2: name, 3: city, 4: coordinate).
     * @param flag2 Type of input for the destination (1: code, 2: name, 3: city, 4: coordinate).
     * @param allowedAirlines Set of allowed airlines (empty for any).
     * @param minimizeAirlines Flag to minimize the number of unique airlines in the path.
     * @return Vector of vector of airports representing the best flight paths.
     */
    std::vector<std::vector<Airport>> listBestFlights(const int &flag1, const int &flag2, const set<string> &allowedAirlines, bool minimizeAirlines) const;

    /**
     * @brief Convert an airport code to its corresponding name.\n
     * Time Complexity: O(V) where V is the number of vertices in the graph.
     *
     * This function takes an airport code and searches the dataset to find the corresponding airport name.
     *
     * @param code The unique IATA code of the airport.
     * @return std::string The name of the airport.
     * @throw std::runtime_error if the airport with the given code is not found.
     */
    std::string airportCodeToName(const std::string &code);

    /**
     * @brief Convert an airline code to its corresponding name.\n
     * Time Complexity: O(N) where N is the number of lines in the airlines.csv.
     *
     * This function takes an airline code and searches the dataset to find the corresponding airline name.
     *
     * @param code The unique ICAO code of the airline.
     * @return std::string The name of the airline.
     * @throw std::runtime_error if the airline with the given code is not found.
     */
    std::string airlineCodeToName(const std::string &code);
};

/**
 * @brief Depth-first search for identifying articulation points in the airport graph.\n
 * Time Complexity: O(V + E) where V is the number of vertices in the graph.
 *
 * @param g The airport graph.
 * @param v The current vertex in the DFS traversal.
 * @param l Set to store the identified articulation points.
 * @param i Reference to the current DFS iteration number.
 */
void dfs_art(Graph<Airport> &g, Vertex<Airport> *v, set<string> &l, int &i);

/**
 * @brief Calculates the Haversine distance between two geographical points.\n
 * Time Complexity: O(1)
 * @param lat1 Latitude of the first point.
 * @param lon1 Longitude of the first point.
 * @param lat2 Latitude of the second point.
 * @param lon2 Longitude of the second point.
 * @return Haversine distance between the two points.
 */
double haversineDistance(double lat1, double lon1, double lat2, double lon2);

#endif
