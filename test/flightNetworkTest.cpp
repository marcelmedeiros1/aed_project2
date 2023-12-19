#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

// g++ -o flightNetworkTest flightNetworkTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testNumOfAirports(FlightNetwork &flightnetwork)
{
    if (flightnetwork.getGlobalNumOfAirports() != 3019)
    {
        std::cerr << "Error: getGlobalNumOfAirports()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testTotalNumOfFlights(FlightNetwork &flightnetwork)
{
    if (flightnetwork.getGlobalNumOfFlights() != 63832)
    {
        std::cerr << "Error: getGlobalNumOfFlights()" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testHaversine(FlightNetwork &flightnetwork)
{
    Airport recife("REC");
    Airport natal("NAT");
    Airport salvador("SSA");
    Airport porto("OPO");

    Vertex<Airport> *recife_vertex = flightnetwork.getAiportsGraph().findVertex(recife);
    Vertex<Airport> *natal_vertex = flightnetwork.getAiportsGraph().findVertex(natal);
    Vertex<Airport> *salvador_vertex = flightnetwork.getAiportsGraph().findVertex(salvador);
    Vertex<Airport> *porto_vertex = flightnetwork.getAiportsGraph().findVertex(porto);

    double RecToNatal = haversineDistance(recife_vertex->getInfo().getPosition().first, recife_vertex->getInfo().getPosition().second, natal_vertex->getInfo().getPosition().first, natal_vertex->getInfo().getPosition().second);
    double NatalToSalvador = haversineDistance(natal_vertex->getInfo().getPosition().first, natal_vertex->getInfo().getPosition().second, salvador_vertex->getInfo().getPosition().first, salvador_vertex->getInfo().getPosition().second);
    double RecToPorto = haversineDistance(recife_vertex->getInfo().getPosition().first, recife_vertex->getInfo().getPosition().second, porto_vertex->getInfo().getPosition().first, porto_vertex->getInfo().getPosition().second);

    std::cout << "Distance from Recife to Natal -> " << RecToNatal << '\n'
              << "Distance from Natal to Salvador -> " << NatalToSalvador << '\n'
              << "Distance from Recife to Porto -> " << RecToPorto << '\n';
}

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    try
    {
        testNumOfAirports(flightnetwork);
        testTotalNumOfFlights(flightnetwork);
        testHaversine(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
