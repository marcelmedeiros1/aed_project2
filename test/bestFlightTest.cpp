#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

// g++ -o bestFlightTest bestFlightTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp

void testBestFlight(FlightNetwork &flightnetwork)
{
    Airport rec = flightnetwork.codeCriteria("REC");
    Airport opo = flightnetwork.codeCriteria("OPO");
    vector<vector<Airport>> bestOption = flightnetwork.bestFlight(rec, opo);

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

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");

    try
    {
        testBestFlight(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
