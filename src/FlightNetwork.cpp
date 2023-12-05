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

Graph<Airport> FlightNetwork::getAiportsGraph()
{
    return airportsGraph;
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

pair<int, int> FlightNetwork::numFlightsAirport(const Airport &airport)
{

    vector<Edge<Airport>> res = airportsGraph.EdgesAtDistanceDFS(airport, 0);

    int numFlights = 0;
    set<string> differentAirlines;
    for (Edge<Airport> e : res)
    {
        differentAirlines.insert(e.getInfo());
        numFlights++;
    }

    pair<int, int> final{numFlights, differentAirlines.size()};

    return final;
}
int FlightNetwork::numFlightsCity(const string &city) const
{
    int res = 0;
    for (Vertex<Airport> *v : airportsGraph.getVertexSet())
    {
        Airport air = v->getInfo();
        vector<Edge<Airport>> adj = v->getAdj();
        if (air.getCity() == city)
            res += adj.size();
    }
    return res;
}
int FlightNetwork::numFlightsAirline(Airline &airline) const
{
    int res = 0;
    for (Vertex<Airport> *v : airportsGraph.getVertexSet())
    {
        vector<Edge<Airport>> adj = v->getAdj();
        for (Edge<Airport> e : adj)
        {
            if (e.getInfo() == airline.getCode())
                res++;
        }
    }
    return res;
}

set<string> FlightNetwork::getDiffCountriesAirport(const Airport &airport) const
{
    set<string> countries;
    Vertex<Airport> *airport_vertex = airportsGraph.findVertex(airport);

    for (const Edge<Airport> &e : airport_vertex->getAdj())
    {
        Vertex<Airport> *destiny = e.getDest();
        countries.insert(destiny->getInfo().getCountry());
    }

    return countries;
}

set<string> FlightNetwork::getDiffCountriesCity(const string &city) const
{
    set<string> countries;
    for (const Vertex<Airport> *v : airportsGraph.getVertexSet())
        if (v->getInfo().getCity() == city)
            for (const Edge<Airport> &e : v->getAdj())
                countries.insert(e.getDest()->getInfo().getCountry());

    return countries;
}

tuple<set<string>, set<string>, set<string>> FlightNetwork::getAirportDestinations(const Airport &airport) const
{
    set<string> airports, cities, countries;

    Vertex<Airport> *airport_vertex = airportsGraph.findVertex(airport);
    for (const Edge<Airport> &e : airport_vertex->getAdj())
    {
        Vertex<Airport> *destination = e.getDest();

        airports.insert(destination->getInfo().getName());
        cities.insert(destination->getInfo().getCity());
        countries.insert(destination->getInfo().getCountry());
    }

    return {airports, cities, countries};
}
