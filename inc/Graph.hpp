#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
template <class T>
class Edge;

template <class T>
class Graph;

template <class T>
class Vertex;

template <class T>
class Vertex
{
    T info;
    std::vector<Edge<T>> adj;
    bool visited;
    bool processing;
    int indegree;
    int num;
    int low;

public:
    Vertex(T in);

    T getInfo() const;
    void setInfo(T in);

    bool isVisited() const;
    void setVisited(bool v);

    bool isProcessing() const;
    void setProcessing(bool p);

    void setInDegree(int i);
    int getInDegree();

    int getNum() const;
    void setNum(int num);

    int getLow() const;
    void setLow(int low);

    void addEdge(Vertex<T> *dest, std::string in, double w);
    bool removeEdgeTo(Vertex<T> *d);

    const std::vector<Edge<T>> &getAdj() const;
    void setAdj(const std::vector<Edge<T>> &adj_vec);
    bool operator<(Vertex<T> *other) { return this->adj.size() > other->getAdj().size(); }
    friend class Graph<T>;
};

template <class T>
class Edge
{
    Vertex<T> *dest;
    std::string info;
    double weight;

public:
    Edge(Vertex<T> *d, std::string in, double w);

    Vertex<T> *getDest() const;
    void setDest(Vertex<T> *dest);

    std::string getInfo() const;
    void setInfo(std::string in);

    double getWeight() const;
    void setWeight(double weight);

    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph
{
    std::vector<Vertex<T> *> vertexSet;

public:
    Vertex<T> *findVertex(const T &in) const;

    int getNumVertex() const;

    bool addVertex(const T &in);
    bool removeVertex(const T &in);

    bool addEdge(const T &sourc, const T &dest, const std::string &in, double w);
    bool removeEdge(const T &sourc, const T &dest);

    std::vector<Vertex<T> *> getVertexSet() const;

    void dfsVisit(Vertex<T> *v, std::vector<T> &res) const;
    std::vector<T> dfs() const;
    std::vector<T> dfs(const T &source) const;

    std::vector<T> nodesAtDistanceDFS(const T &source, int k);
    std::vector<Edge<T>> EdgesAtDistanceDFS(const T &source, int k);

    std::vector<T> bfs(const T &source) const;
    std::vector<std::pair<int, T>> bfsDistance(Vertex<T> *source);
    std::vector<std::pair<int, T>> dijkstra(const T &source);
    void inDegree(Vertex<T> *source);
};

/*
    Vertex functions
*/

template <class T>
Vertex<T>::Vertex(T in) : info(in), visited(false), processing(false) {}

template <class T>
T Vertex<T>::getInfo() const
{
    return info;
}

template <class T>
void Vertex<T>::setInfo(T in)
{
    info = in;
}

template <class T>
bool Vertex<T>::isVisited() const
{
    return visited;
}

template <class T>
void Vertex<T>::setVisited(bool v)
{
    visited = v;
}

template <class T>
bool Vertex<T>::isProcessing() const
{
    return processing;
}

template <class T>
void Vertex<T>::setProcessing(bool p)
{
    processing = p;
}

template <class T>
void Vertex<T>::setInDegree(int i)
{
    indegree = i;
}

template <class T>
int Vertex<T>::getInDegree()
{
    return indegree;
}

template <class T>
int Vertex<T>::getNum() const
{
    return num;
}

template <class T>
void Vertex<T>::setNum(int num)
{
    Vertex::num = num;
}

template <class T>
int Vertex<T>::getLow() const
{
    return low;
}

template <class T>
void Vertex<T>::setLow(int low)
{
    Vertex::low = low;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, std::string in, double w)
{
    adj.push_back(Edge<T>(d, in, w));
}

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d)
{
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest == d)
        {
            adj.erase(it);
            return true;
        }
    return false;
}

template <class T>
const std::vector<Edge<T>> &Vertex<T>::getAdj() const
{
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const std::vector<Edge<T>> &adj_vec)
{
    adj = adj_vec;
}

/*
    Edge functions
*/

template <class T>
Edge<T>::Edge(Vertex<T> *d, std::string in, double w) : dest(d), info(in), weight(w) {}

template <class T>
Vertex<T> *Edge<T>::getDest() const
{
    return dest;
}

template <class T>
void Edge<T>::setDest(Vertex<T> *d)
{
    dest = d;
}

template <class T>
std::string Edge<T>::getInfo() const
{
    return info;
}

template <class T>
void Edge<T>::setInfo(std::string in)
{
    info = in;
}

template <class T>
double Edge<T>::getWeight() const
{
    return weight;
}

template <class T>
void Edge<T>::setWeight(double weight)
{
    Edge::weight = weight;
}

/*
    Graph functions
*/

template <class T>
Vertex<T> *Graph<T>::findVertex(const T &in) const
{
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

template <class T>
int Graph<T>::getNumVertex() const
{
    return vertexSet.size();
}

template <class T>
bool Graph<T>::addVertex(const T &in)
{
    if (findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

template <class T>
bool Graph<T>::removeVertex(const T &in)
{
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info == in)
        {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, const std::string &in, double w)
{
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2, in, w);
    return true;
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest)
{
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const
{
    return vertexSet;
}

template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, std::vector<T> &res) const
{
    v->setVisited(true);
    res.push_back(v->getInfo());

    for (const Edge<T> &edge : v->getAdj())
    {
        Vertex<T> *neighbor = edge.getDest();

        if (!neighbor->isVisited())
        {
            dfsVisit(neighbor, res);
        }
    }
}

template <class T>
std::vector<T> Graph<T>::dfs() const
{
    std::vector<T> res;

    for (Vertex<T> *v : vertexSet)
    {
        if (!v->isVisited())
        {
            dfsVisit(v, res);
        }
    }

    for (Vertex<T> *v : vertexSet)
    {
        v->setVisited(false);
    }

    return res;
}

template <class T>
std::vector<T> Graph<T>::dfs(const T &source) const
{
    std::vector<T> res;
    res.push_back(source);

    Vertex<T> *source_vertex = findVertex(source);
    source_vertex->setVisited(true);

    for (const Edge<T> &e : source_vertex->getAdj())
    {
        Vertex<T> *neighbor = e.getDest();

        if (!neighbor->isVisited())
            dfsVisit(neighbor, res);
    }

    for (Vertex<T> *vtx : vertexSet)
    {
        vtx->setVisited(false);
    }

    return res;
}

template <class T>
std::vector<T> Graph<T>::nodesAtDistanceDFS(const T &source, int k)
{
    std::vector<T> res;
    Vertex<T> *aux;

    for (auto v : vertexSet)
    {
        v->setVisited(false);
    }

    aux = this->findVertex(source);

    nodesAtDistanceDFSVisit(aux, k, res);

    return res;
}

template <class T>
void nodesAtDistanceDFSVisit(Vertex<T> *v, int k, std::vector<T> &res)
{
    v->setVisited(true);
    if (k == 0)
    {
        res.push_back(v->getInfo());
        return;
    }
    for (Edge<T> e : v->getAdj())
    {
        auto w = e.getDest();
        if (!w->isVisited())
        {
            nodesAtDistanceDFSVisit(w, k - 1, res);
        }
    }
}

template <class T>
void nodesAtDistanceDFSVisit(Vertex<T> *v, int k, std::vector<Edge<T>> &res)
{
    v->setVisited(true);
    if (k == 0)
    {
        for (auto aux : v->getAdj())
        {
            res.push_back(aux);
        }
        return;
    }
    for (Edge<T> e : v->getAdj())
    {
        auto w = e.getDest();
        if (!w->isVisited())
        {
            nodesAtDistanceDFSVisit(w, k - 1, res);
        }
    }
}

template <class T>
std::vector<Edge<T>> Graph<T>::EdgesAtDistanceDFS(const T &source, int k)
{
    std::vector<Edge<T>> res;
    Vertex<T> *aux;

    for (auto v : vertexSet)
    {
        v->setVisited(false);
    }

    aux = this->findVertex(source);

    nodesAtDistanceDFSVisit(aux, k, res);

    return res;
}

template <class T>
std::vector<T> Graph<T>::bfs(const T &source) const
{
    std::vector<T> res;
    std::queue<Vertex<T> *> aux;

    for (Vertex<T> *v : vertexSet)
        v->setVisited(false);

    Vertex<T> *source_vertex = findVertex(source);
    source_vertex->setVisited(true);
    aux.push(source_vertex);

    while (!aux.empty())
    {
        Vertex<T> *curr = aux.front();
        aux.pop();
        res.push_back(curr->getInfo());

        for (const Edge<T> &e : curr->getAdj())
        {
            Vertex<T> *neighbor = e.getDest();
            if (!neighbor->isVisited())
            {
                neighbor->setVisited(true);
                aux.push(neighbor);
            }
        }
    }

    return res;
}

template <class T>
std::vector<std::pair<int, T>> Graph<T>::bfsDistance(Vertex<T> *source)
{
    std::vector<std::pair<int, T>> res;
    std::queue<Vertex<T> *> aux;

    for (Vertex<T> *v : vertexSet)
        v->setVisited(false);

    source->setVisited(true);
    aux.push(source);
    int distance = 0;

    while (!aux.empty())
    {
        Vertex<T> *curr = aux.front();
        aux.pop();
        res.push_back({distance, curr->getInfo()});

        for (const Edge<T> &e : curr->getAdj())
        {
            Vertex<T> *neighbor = e.getDest();
            if (!neighbor->isVisited())
            {
                neighbor->setVisited(true);
                aux.push(neighbor);
            }
        }
        distance++;
    }

    return res;
}
template <class T>
void Graph<T>::inDegree(Vertex<T> *source)
{
    int res = 0;
    if (source == NULL)
        return;

    for (auto it = vertexSet.begin(); it != vertexSet.end(); ++it)
    {
        Vertex<T> *aux = *it;
        std::vector<Edge<T>> adj = aux->getAdj();
        for (auto ed : adj)
        {
            if (ed.getDest() == source)
                res++;
        }
    }
    source->setInDegree(res);
}

/*Using Dijkstra algorithm to find shortest paths in the graph
template <class T>
struct DijkstraInfo {
    Vertex<T>* vertex;
    double distance;

    DijkstraInfo(Vertex<T>* v, double d) : vertex(v), distance(d) {}

    bool operator>(const DijkstraInfo& other) const {
        return distance > other.distance;
    }


};

template <class T>
std::vector<std::pair<int, T>> Graph<T>::dijkstra(const T& source) {
    std::vector<std::pair<int, T>> shortestPaths;

    // Priority queue to select the vertex with the minimum distance
    std::priority_queue<DijkstraInfo<T>, std::vector<DijkstraInfo<T>>, std::greater<>> pq;

    // Initialize distances to all vertices as infinity
    std::unordered_map<Vertex<T>*, double> distances;
    for (Vertex<T>* vertex : vertexSet) {
        distances[vertex] = 1000000000000000000000.0;
    }

    // Set the distance of the source vertex to 0
    Vertex<T>* sourceVertex = this->findVertex(source);
    distances[sourceVertex] = 0;
    pq.push(DijkstraInfo<T>(sourceVertex, 0));

    while (!pq.empty()) {
        DijkstraInfo<T> currentInfo = pq.top();
        pq.pop();

        Vertex<T>* currentVertex = currentInfo.vertex;
        double currentDistance = currentInfo.distance;

        // Update the distances of neighboring vertices
        for (const Edge<T>& edge : currentVertex->getAdj()) {
            Vertex<T>* neighborVertex = edge.getDest();
            double edgeWeight = edge.getWeight();

            double newDistance = currentDistance + edgeWeight;

            if (newDistance < distances[neighborVertex]) {
                distances[neighborVertex] = newDistance;
                pq.push(DijkstraInfo<T>(neighborVertex, newDistance));
            }
        }
    }

    // Convert the distances to the desired format (pair of stops and airport)
    for (const auto& entry : distances) {
        Vertex<T>* vertex = entry.first;
        double distance = entry.second;
        shortestPaths.emplace_back(static_cast<int>(distance), vertex->getInfo());
    }

    return shortestPaths;
}
*/

#endif
