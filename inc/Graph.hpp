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

/**
 * @brief Represents a vertex in a graph with generic information of type T.
 * @tparam T The type of information stored in the vertex.
 */
template <class T>
class Vertex
{
    /** The information stored in the vertex. */
    T info;

    /** The vector of edges adjacent to this vertex. */
    std::vector<Edge<T>> adj;

    /** Flag indicating if the vertex has been visited during graph traversal. */
    bool visited;

    /** Flag indicating if the vertex is currently being processed during traversal. */
    bool processing;

    /** The indegree of the vertex in a directed graph. */
    int indegree;

    /** Numeric identifier for the vertex. */
    int num;

    /** Low value used in Tarjan's algorithm for finding strongly connected components. */
    int low;

    /** Distance of the vertex in certain graph traversal algorithms. */
    int distance;

public:
    /**
     * @brief Constructor for creating a vertex with the given information.
     * @param in The information to be stored in the vertex.
     */
    Vertex(T in);

    /**
     * @brief Gets the information stored in the vertex.
     * @return The information stored in the vertex.
     */
    T getInfo() const;

    /**
     * @brief Sets the information stored in the vertex.
     * @param in The new information to be stored in the vertex.
     */
    void setInfo(T in);

    /**
     * @brief Checks if the vertex has been visited during graph traversal.
     * @return True if the vertex has been visited, false otherwise.
     */
    bool isVisited() const;

    /**
     * @brief Sets the visited status of the vertex.
     * @param v The new visited status.
     */
    void setVisited(bool v);

    /**
     * @brief Checks if the vertex is currently being processed during traversal.
     * @return True if the vertex is being processed, false otherwise.
     */
    bool isProcessing() const;

    /**
     * @brief Sets the processing status of the vertex.
     * @param p The new processing status.
     */
    void setProcessing(bool p);

    /**
     * @brief Sets the indegree of the vertex.
     * @param i The new indegree of the vertex.
     */
    void setInDegree(int i);

    /**
     * @brief Gets the indegree of the vertex.
     * @return The indegree of the vertex.
     */
    int getInDegree();

    /**
     * @brief Gets the numeric identifier of the vertex.
     * @return The numeric identifier of the vertex.
     */
    int getNum() const;

    /**
     * @brief Sets the numeric identifier of the vertex.
     * @param num The new numeric identifier.
     */
    void setNum(int num);

    /**
     * @brief Gets the low value of the vertex.
     * @return The low value of the vertex.
     */
    int getLow() const;

    /**
     * @brief Sets the low value of the vertex.
     * @param low The new low value.
     */
    void setLow(int low);

    /**
     * @brief Gets the distance of the vertex.
     * @return The distance of the vertex.
     */
    int getDistance() const;

    /**
     * @brief Sets the distance of the vertex.
     * @param distance The new distance of the vertex.
     */
    void setDistance(int distance);

    /**
     * @brief Adds an edge from this vertex to the specified destination vertex with a given weight.
     * @param d The destination vertex.
     * @param in The information associated with the edge.
     * @param w The weight of the edge.
     */
    void addEdge(Vertex<T> *d, std::string in, double w);

    /**
     * @brief Removes the edge from this vertex to the specified destination vertex.
     * @param d The destination vertex.
     * @return True if the edge was successfully removed, false otherwise.
     */
    bool removeEdgeTo(Vertex<T> *d);

    /**
     * @brief Gets the vector of edges adjacent to this vertex.
     * @return The vector of edges adjacent to this vertex.
     */
    const std::vector<Edge<T>> &getAdj() const;

    /**
     * @brief Sets the vector of edges adjacent to this vertex.
     * @param adj_vec The new vector of edges adjacent to this vertex.
     */
    void setAdj(const std::vector<Edge<T>> &adj_vec);

    friend class Graph<T>; // Allow Graph class to access private members of Vertex.
};

/**
 * @brief Represents an edge between two vertices in a graph with generic information of type T.
 * @tparam T The type of information stored in the edge.
 */
template <class T>
class Edge
{
    /** The destination vertex of the edge. */
    Vertex<T> *dest;

    /** Information associated with the edge. */
    std::string info;

    /** The weight of the edge. */
    double weight;

public:
    /**
     * @brief Constructor for creating an edge with a specified destination vertex, information, and weight.
     * @param d The destination vertex of the edge.
     * @param in The information associated with the edge.
     * @param w The weight of the edge.
     */
    Edge(Vertex<T> *d, std::string in, double w);

    /**
     * @brief Gets the destination vertex of the edge.
     * @return The destination vertex of the edge.
     */
    Vertex<T> *getDest() const;

    /**
     * @brief Sets the destination vertex of the edge.
     * @param d The new destination vertex of the edge.
     */
    void setDest(Vertex<T> *d);

    /**
     * @brief Gets the information associated with the edge.
     * @return The information associated with the edge.
     */
    std::string getInfo() const;

    /**
     * @brief Sets the information associated with the edge.
     * @param in The new information associated with the edge.
     */
    void setInfo(std::string in);

    /**
     * @brief Gets the weight of the edge.
     * @return The weight of the edge.
     */
    double getWeight() const;

    /**
     * @brief Sets the weight of the edge.
     * @param weight The new weight of the edge.
     */
    void setWeight(double weight);

    friend class Graph<T>;  /**< Allow Graph class to access private members of Edge. */
    friend class Vertex<T>; /**< Allow Vertex class to access private members of Edge. */
};

/**
 * @brief Represents a generic graph with vertices of type T.
 * @tparam T The type of information stored in the vertices of the graph.
 */
template <class T>
class Graph
{
    /** The vector of vertices in the graph. */
    std::vector<Vertex<T> *> vertexSet;

public:
    /**
     * @brief Finds a vertex with a given information in the graph.
     * @param in The information to search for in the vertices.
     * @return Pointer to the vertex with the given information, or nullptr if not found.
     */
    Vertex<T> *findVertex(const T &in) const;

    /**
     * @brief Gets the number of vertices in the graph.
     * @return The number of vertices in the graph.
     */

    int getNumVertex() const;

    /**
     * @brief Adds a vertex with the given information to the graph.
     * @param in The information to be stored in the new vertex.
     * @return True if the vertex is added successfully, false if the vertex already exists.
     */
    bool addVertex(const T &in);

    /**
     * @brief Removes the vertex with the given information from the graph.
     * @param in The information of the vertex to be removed.
     * @return True if the vertex is removed successfully, false if the vertex is not found.
     */
    bool removeVertex(const T &in);

    /**
     * @brief Adds an edge between vertices with source and destination information.
     * @param sourc The information of the source vertex.
     * @param dest The information of the destination vertex.
     * @param in The information associated with the edge.
     * @param w The weight of the edge.
     * @return True if the edge is added successfully, false if the source or destination vertex is not found.
     */
    bool addEdge(const T &sourc, const T &dest, const std::string &in, double w);

    /**
     * @brief Removes the edge between vertices with source and destination information.
     * @param sourc The information of the source vertex.
     * @param dest The information of the destination vertex.
     * @return True if the edge is removed successfully, false if the source or destination vertex is not found.
     */
    bool removeEdge(const T &sourc, const T &dest);

    /**
     * @brief Gets the vector of vertices in the graph.
     * @return The vector of vertices in the graph.
     */
    std::vector<Vertex<T> *> getVertexSet() const;

    /**
     * @brief Helper function for depth-first search traversal of the graph.
     * @param v The pointer to the current vertex being visited.
     * @param res The vector to store the information of vertices in the order they are visited.
     */
    void dfsVisit(Vertex<T> *v, std::vector<T> &res) const;

    /**
     * @brief Performs depth-first search traversal of the graph.
     * @return A vector containing the information of vertices in the order they are visited.
     */
    std::vector<T> dfs() const;

    /**
     * @brief Performs depth-first search traversal of the graph starting from a specific vertex.
     * @param source The information of the starting vertex.
     * @return A vector containing the information of vertices in the order they are visited.
     */
    std::vector<T> dfs(const T &source) const;

    /**
     * @brief Finds nodes at a specific distance from a source vertex using depth-first search.
     * @param source The information of the source vertex.
     * @param k The distance from the source vertex.
     * @return A vector containing the information of vertices at the specified distance.
     */
    std::vector<T> nodesAtDistanceDFS(const T &source, int k);

    /**
     * @brief Finds edges at a specific distance from a source vertex using depth-first search.
     * @param source The information of the source vertex.
     * @param k The distance from the source vertex.
     * @return A vector containing the edges at the specified distance.
     */
    std::vector<Edge<T>> EdgesAtDistanceDFS(const T &source, int k);

    /**
     * @brief Performs breadth-first search traversal of the graph starting from a specific vertex.
     * @param source The information of the starting vertex.
     * @return A vector containing the information of vertices in the order they are visited.
     */
    std::vector<T> bfs(const T &source) const;

    /**
     * @brief Performs breadth-first search traversal of the graph starting from a specific vertex
     * and returns a vector of pairs containing the distance and information of each vertex.
     * @param source The pointer to the starting vertex.
     * @return A vector of pairs containing the distance and information of each vertex.
     */
    std::vector<std::pair<int, T>> bfsDistance(Vertex<T> *source);

    /**
     * @brief Determines the in-degree of a specific vertex in the graph.
     * @param source The pointer to the vertex for which the in-degree is calculated.
     */
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
void Vertex<T>::setDistance(int distance)
{
    Vertex::distance = distance;
}

template <class T>
int Vertex<T>::getDistance() const
{
    return distance;
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
    {
        v->setVisited(false);
        v->setDistance(10000);
    }

    source->setVisited(true);
    source->setDistance(0);
    aux.push(source);

    while (!aux.empty())
    {
        Vertex<T> *curr = aux.front();
        aux.pop();
        res.push_back({curr->getDistance(), curr->getInfo()});

        for (const Edge<T> &e : curr->getAdj())
        {
            Vertex<T> *neighbor = e.getDest();
            if (!neighbor->isVisited())
            {
                neighbor->setVisited(true);
                neighbor->setDistance(curr->getDistance() + 1);
                aux.push(neighbor);
            }
        }
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

#endif
