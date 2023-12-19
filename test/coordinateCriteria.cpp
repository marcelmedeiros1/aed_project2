#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

//

void testCoordinateCriteria(FlightNetwork &flightnetwork)
{
    vector<Airport> res = flightnetwork.coordinateCriteria(48.864716, 2.349014, 100);

    for (const Airport &a : res)
        cout << a.getName() << '\n';
    cout << '\n';
}

int main()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    try
    {
        testCoordinateCriteria(flightnetwork);

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
