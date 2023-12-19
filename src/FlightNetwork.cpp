#include "../inc/FlightNetwork.hpp"
using namespace std;

double haversineDistance(double lat1, double lon1, double lat2, double lon2)
{
    const double earthRadius = 6371.0;

    double diffLat = (lat2 - lat1) * M_PI / 180.0;
    double diffLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1)*M_PI / 180.0;
    lat2 = (lat2)*M_PI / 180.0;

    double a = pow(sin(diffLat / 2), 2) + pow(sin(diffLon / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));

    return earthRadius * c;
}

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
        double distance = haversineDistance(source_vertex->getInfo().getPosition().first, source_vertex->getInfo().getPosition().second, target_vertex->getInfo().getPosition().first, target_vertex->getInfo().getPosition().second);
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

set<string> FlightNetwork::getAirportsDestinations(const Airport &airport) const
{
    set<string> airports;
    Vertex<Airport> *airport_vertex = airportsGraph.findVertex(airport);

    for (const Edge<Airport> &e : airport_vertex->getAdj())
    {
        Vertex<Airport> *destination = e.getDest();
        airports.insert(destination->getInfo().getName());
    }

    return airports;
}

set<string> FlightNetwork::getCitiesDestinations(const Airport &airport) const
{
    set<string> cities;
    Vertex<Airport> *airport_vertex = airportsGraph.findVertex(airport);

    for (const Edge<Airport> &e : airport_vertex->getAdj())
    {
        Vertex<Airport> *destination = e.getDest();
        cities.insert(destination->getInfo().getCity());
    }

    return cities;
}

set<string> FlightNetwork::getCountriesDestinations(const Airport &airport) const
{
    set<string> countries;
    Vertex<Airport> *airport_vertex = airportsGraph.findVertex(airport);

    for (const Edge<Airport> &e : airport_vertex->getAdj())
    {
        Vertex<Airport> *destination = e.getDest();
        countries.insert(destination->getInfo().getCountry());
    }

    return countries;
}

set<string> FlightNetwork::getReachableAirports(const Airport &airport, const int &distance)
{
    set<string> reachableAirports;
    vector<Airport> aux = airportsGraph.nodesAtDistanceDFS(airport, distance);

    for (const Airport &air : aux)
        reachableAirports.insert(air.getName());

    return reachableAirports;
}

set<string> FlightNetwork::getReachableCities(const Airport &airport, const int &distance)
{
    set<string> reachableCities;
    vector<Airport> aux = airportsGraph.nodesAtDistanceDFS(airport, distance);

    for (const Airport &air : aux)
        reachableCities.insert(air.getCity());

    return reachableCities;
}

set<string> FlightNetwork::getReachableCountries(const Airport &airport, const int &distance)
{
    set<string> reachableCountries;
    vector<Airport> aux = airportsGraph.nodesAtDistanceDFS(airport, distance);

    for (const Airport &air : aux)
        reachableCountries.insert(air.getCountry());

    return reachableCountries;
}

int FlightNetwork::maximumTrip(vector<pair<string, string>> &airports)
{
    int maxStops = -1;

    for (Vertex<Airport> *sourceVertex : airportsGraph.getVertexSet())
    {
        const Airport &sourceAirport = sourceVertex->getInfo();

        vector<pair<int, Airport>> shortestPaths = airportsGraph.bfsDistance(sourceVertex);

        for (const auto &destinationPair : shortestPaths)
        {
            const Airport &destinationAirport = destinationPair.second;
            int stops = destinationPair.first;

            if (stops > maxStops)
            {
                maxStops = stops;
                airports.clear();
                airports.push_back({sourceAirport.getName(), destinationAirport.getName()});
            }
            else if (stops == maxStops)
            {
                airports.push_back({sourceAirport.getName(), destinationAirport.getName()});
            }
        }
    }

    return maxStops;
}

set<string> FlightNetwork::getGreatestTraffic(const int &k)
{
    for (Vertex<Airport> *sourceVertex : airportsGraph.getVertexSet())
    {
        airportsGraph.inDegree(sourceVertex);
    }

    multiset<Vertex<Airport> *, function<bool(Vertex<Airport> *, Vertex<Airport> *)>> aux(
        [](Vertex<Airport> *v1, Vertex<Airport> *v2)
        {
            return (v1->getAdj().size() + v1->getInDegree()) > (v2->getAdj().size() + v2->getInDegree());
        });
    set<string> greatest;

    for (Vertex<Airport> *sourceVertex : airportsGraph.getVertexSet())
    {
        aux.insert(sourceVertex);
    }
    for (auto it = aux.begin(); it != aux.end() && greatest.size() < k; ++it)
    {
        Vertex<Airport> *sourceVertex = *it;
        greatest.insert(sourceVertex->getInfo().getName());
    }
    return greatest;
}

void dfs_art(Graph<Airport> &g, Vertex<Airport> *v, set<string> &l, int &i)
{
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;

    for (const Edge<Airport> &e : v->getAdj())
    {
        Vertex<Airport> *w = e.getDest();

        if (w->getNum() == 0)
        {
            children++;
            dfs_art(g, w, l, i);
            v->setLow(min(v->getLow(), w->getLow()));

            if (v->getNum() != 1 && w->getLow() >= v->getNum())
                l.insert(v->getInfo().getName());
        }
        else if (w->getNum() > 0)
            v->setLow(min(v->getLow(), w->getNum()));
    }

    if (v->getNum() == 1 && children > 1)
        l.insert(v->getInfo().getName());
}

set<string> FlightNetwork::getEssentialAirports()
{
    set<string> res;
    int i = 0;

    for (Vertex<Airport> *v : airportsGraph.getVertexSet())
        v->setNum(0);

    for (Vertex<Airport> *v : airportsGraph.getVertexSet())
        if (v->getNum() == 0)
            dfs_art(airportsGraph, v, res, i);

    return res;
}

Airport FlightNetwork::codeCriteria(const string &code) const
{
    for (Vertex<Airport> *a : airportsGraph.getVertexSet())
    {
        if (a->getInfo().getCode() == code)
        {
            Airport res = a->getInfo();
            return res;
        }
    }

    throw runtime_error("No airport with this code.");
}

Airport FlightNetwork::nameCriteria(const string &name) const
{
    for (Vertex<Airport> *a : airportsGraph.getVertexSet())
    {
        if (a->getInfo().getName() == name)
        {
            Airport res = a->getInfo();
            return res;
        }
    }

    throw runtime_error("No airport with this name.");
}

vector<Airport> FlightNetwork::cityCriteria(const string &city) const
{
    vector<Airport> res;
    for (Vertex<Airport> *a : airportsGraph.getVertexSet())
    {
        if (a->getInfo().getCity() == city)
        {
            Airport airport = a->getInfo();
            res.push_back(airport);
        }
    }

    if (res.empty())
        throw runtime_error("No city with this name.");

    return res;
}

vector<Airport> FlightNetwork::coordinateCriteria(const float &lat, const float &lon, const double &radius) const
{
    vector<Airport> res;
    for (Vertex<Airport> *a : airportsGraph.getVertexSet())
    {
        double distance = haversineDistance(lat, lon, a->getInfo().getPosition().first, a->getInfo().getPosition().second);
        if (distance <= radius)
            res.push_back(a->getInfo());
    }

    if (res.empty())
        throw runtime_error("There are no airports in this area.");

    return res;
}
