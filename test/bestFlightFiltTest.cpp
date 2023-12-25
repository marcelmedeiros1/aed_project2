#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

// g++ -o bestFlightFiltTest bestFlightFiltTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testBestFlightFiltered(FlightNetwork &flightnetwork)
{
    Airport rec = flightnetwork.codeCriteria("REC");
    Airport opo = flightnetwork.codeCriteria("OPO");
    set<string> airlines = { "TAP"};
    vector<vector<Airport>> bestOption = flightnetwork.bestFlight(rec, opo, airlines, false);

    if (!bestOption.empty())
    {
        int stops = bestOption.front().size() - 1;
        cout << "Best route with fewer mount of stops: " << stops << '\n';

        for (const vector<Airport> v : bestOption)
        {
            cout << "OPTION:'\n";
            for (const Airport &a : v)
                cout << a.getCode() << " -> ";
            cout << "\n\n";
        }
    }
    else
    {
        std::cout << "No valid flight option found.'\n";
    }
}

void testListBestOption(FlightNetwork &flightnetwork)
{
    vector<vector<Airport>> res = flightnetwork.listBestFlights(0, 2);

    for (const vector<Airport> v : res)
    {
        cout << "OPTION:\n";
        for (const Airport &a : v)
            cout << a.getCode() << " -> ";
        cout << "\n\n";
    }
}

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    try
    {
        testBestFlightFiltered(flightnetwork);
        //testListBestOption(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
