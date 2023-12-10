#include "../inc/FlightNetwork.hpp"
#include <iostream>
#include <stdexcept>

// g++ -o maxTripTest maxTripTest.cpp ../src/FlightNetwork.cpp ../src/Airline.cpp ../src/Airport.cpp
using namespace std;
void testMaxTrip()
{
    FlightNetwork flightnetwork("../data/airlines.csv", "../data/airports.csv", "../data/flights.csv");
    
    vector<pair<string,string>> sourceDestination;
    int res = flightnetwork.maximumTrip(sourceDestination);

    cout << "The maximum trip is from: ";

    for(pair<string,string> p : sourceDestination){
        cout << "from " << p.first << " to " << p.second << endl;
    }

    cout << "and has distance of " << res;
}

int main()
{
    try
    {
        testMaxTrip();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}