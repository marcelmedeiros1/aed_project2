#include "../inc/FlightNetwork.hpp"
using namespace std;

FlightNetwork::FlightNetwork(const string &airlines_filename, const string &airports_filename, const string &flights_filename)
{
    string line;

    // Load the airports (Vertices)
    ifstream airports_file(airports_filename);

    if (!airports_file.is_open())
    {
        throw runtime_error("Airports file does not exist.");
    }

    getline(airports_file, line);
    while (getline(airports_file, line))
    {
        istringstream iss(line);
        string code, name, city, country, latitude, longitude;

        getline(getline(getline(getline(getline(getline(iss, code, ','), name, ','), city, ','), country, ','), latitude, ','), longitude, '\r');
        float lat = stof(latitude);
        float lon = stof(longitude);
        pair<float, float> pos(lat, lon);

        Airport new_airport(code, name, city, country, pos);
        airportsGraph.addVertex(new_airport);
    }

    // Load the flights (Edges)
    ifstream flights_file(flights_filename);

    if (!flights_file.is_open())
    {
        throw runtime_error("Flights file does not exist.");
    }

    getline(flights_file, line);
    while (getline(flights_file, line))
    {
        istringstream iss(line);
        string source, target, airline;

        getline(getline(getline(iss, source, ','), target, ','), airline, '\r');
        Airport source_airport(source);
        Airport target_airport(target);

        Vertex<Airport> *source_vertex = airportsGraph.findVertex(source_airport);
        Vertex<Airport> *target_vertex = airportsGraph.findVertex(target_airport);
        double distance = sqrt(pow(source_vertex->getInfo().getPosition().first - target_vertex->getInfo().getPosition().first, 2) + pow(source_vertex->getInfo().getPosition().second - target_vertex->getInfo().getPosition().second, 2));

        source_vertex->addEdge(target_vertex, airline, distance);
    }
}

int FlightNetwork::getGlobalNumOfAirports() const
{
    return airportsGraph.getNumVertex();
}

int FlightNetwork::getGlobalNumOfFlights() const
{
    int total = 0;

    for (const Vertex<Airport> *curr_airport : airportsGraph.getVertexSet())
        total += curr_airport->getAdj().size();

    return total;
}
