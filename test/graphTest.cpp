#include "../inc/Graph.hpp"
#include <iostream>
#include <vector>

// g++ -o graphTest graphTest.cpp

template <typename T>
void checkEqual(const T &actual, const T &expected, const std::string &message)
{
    if (actual != expected)
    {
        std::cerr << "Error: " << message << " (Actual: " << actual << ", Expected: " << expected << ")" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

template <typename T>
void checkTrue(bool condition, const std::string &message)
{
    if (!condition)
    {
        std::cerr << "Error: " << message << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testVertex()
{
    // Vertex<T> functions
    Vertex<int> v1(42);
    Vertex<int> v2(99);

    // Test getInfo and setInfo
    if (v1.getInfo() != 42)
    {
        std::cerr << "Error: Vertex getInfo (Actual: " << v1.getInfo() << ", Expected: 42)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    v1.setInfo(77);

    if (v1.getInfo() != 77)
    {
        std::cerr << "Error: Vertex setInfo (Actual: " << v1.getInfo() << ", Expected: 77)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test isVisited and setVisited
    if (v1.isVisited() || v2.isVisited())
    {
        std::cerr << "Error: Vertex isVisited initial state" << std::endl;
        throw std::runtime_error("Test failed");
    }

    v1.setVisited(true);
    v2.setVisited(true);

    if (!v1.isVisited() || !v2.isVisited())
    {
        std::cerr << "Error: Vertex setVisited" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test isProcessing and setProcessing
    if (v1.isProcessing() || v2.isProcessing())
    {
        std::cerr << "Error: Vertex isProcessing initial state" << std::endl;
        throw std::runtime_error("Test failed");
    }

    v1.setProcessing(true);
    v2.setProcessing(true);

    if (!v1.isProcessing() || !v2.isProcessing())
    {
        std::cerr << "Error: Vertex setProcessing" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test addEdge and getAdj
    Vertex<int> v3(123);
    Vertex<int> v4(456);

    v1.addEdge(&v3, "edge_info_1", 2.5);
    v1.addEdge(&v4, "edge_info_2", 3.7);

    if (v1.getAdj().size() != 2)
    {
        std::cerr << "Error: Vertex addEdge and getAdj size (Actual: " << v1.getAdj().size() << ", Expected: 2)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (v1.getAdj()[0].getDest() != &v3 || v1.getAdj()[1].getDest() != &v4)
    {
        std::cerr << "Error: Vertex addEdge and getAdj dest" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (v1.getAdj()[0].getWeight() != 2.5 || v1.getAdj()[1].getWeight() != 3.7)
    {
        std::cerr << "Error: Vertex addEdge and getAdj weight" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testEdge()
{
    // Edge<T> functions
    Edge<int> e1(nullptr, "edge_info_1", 3.21);
    Edge<int> e2(nullptr, "edge_info_2", 4.5);
    Edge<int> e3(nullptr, "edge_info_3", 1.0);

    // Test getInfo
    if (e1.getInfo() != "edge_info_1")
    {
        std::cerr << "Error: Edge getInfo (Actual: " << e1.getInfo() << ", Expected: 'edge_info_1')" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (e2.getInfo() != "edge_info_2")
    {
        std::cerr << "Error: Edge getInfo (Actual: " << e2.getInfo() << ", Expected: 'edge_info_2')" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test getWeight
    if (e1.getWeight() != 3.21)
    {
        std::cerr << "Error: Edge getWeight (Actual: " << e1.getWeight() << ", Expected: 3.21)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (e2.getWeight() != 4.5)
    {
        std::cerr << "Error: Edge getWeight (Actual: " << e2.getWeight() << ", Expected: 4.5)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test setInfo
    e1.setInfo("updated_edge_info");
    if (e1.getInfo() != "updated_edge_info")
    {
        std::cerr << "Error: Edge setInfo (Actual: " << e1.getInfo() << ", Expected: 'updated_edge_info')" << std::endl;
        throw std::runtime_error("Test failed");
    }

    // Test setWeight
    e2.setWeight(2.0);
    if (e2.getWeight() != 2.0)
    {
        std::cerr << "Error: Edge setWeight (Actual: " << e2.getWeight() << ", Expected: 2.0)" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testGraph()
{
    // Graph<T> functions
    Graph<int> graph;

    if (graph.getNumVertex() != 0)
    {
        std::cerr << "Error: Graph getNumVertex (Actual: " << graph.getNumVertex() << ", Expected: 0)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.addVertex(1))
    {
        std::cerr << "Error: Graph addVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.addVertex(2))
    {
        std::cerr << "Error: Graph addVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (graph.getNumVertex() != 2)
    {
        std::cerr << "Error: Graph getNumVertex (Actual: " << graph.getNumVertex() << ", Expected: 2)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.addEdge(1, 2, "edge_1_2", 1.5))
    {
        std::cerr << "Error: Graph addEdge" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (graph.getVertexSet().size() != 2)
    {
        std::cerr << "Error: Graph getVertexSet size (Actual: " << graph.getVertexSet().size() << ", Expected: 2)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (graph.getVertexSet()[0]->getAdj().size() != 1)
    {
        std::cerr << "Error: Graph addEdge and getAdj size (Actual: " << graph.getVertexSet()[0]->getAdj().size() << ", Expected: 1)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.removeEdge(1, 2))
    {
        std::cerr << "Error: Graph removeEdge" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.getVertexSet()[0]->getAdj().empty())
    {
        std::cerr << "Error: Graph removeEdge and getAdj empty" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!graph.removeVertex(1))
    {
        std::cerr << "Error: Graph removeVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (graph.getNumVertex() != 1)
    {
        std::cerr << "Error: Graph getNumVertex (Actual: " << graph.getNumVertex() << ", Expected: 1)" << std::endl;
        throw std::runtime_error("Test failed");
    }
}

void testGraphTraversal()
{
    // Additional tests for DFS and BFS
    Graph<char> charGraph;

    if (!charGraph.addVertex('A'))
    {
        std::cerr << "Error: Graph addVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!charGraph.addVertex('B'))
    {
        std::cerr << "Error: Graph addVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!charGraph.addVertex('C'))
    {
        std::cerr << "Error: Graph addVertex" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!charGraph.addEdge('A', 'B', "AB", 1.0))
    {
        std::cerr << "Error: Graph addEdge" << std::endl;
        throw std::runtime_error("Test failed");
    }

    if (!charGraph.addEdge('A', 'C', "AC", 2.0))
    {
        std::cerr << "Error: Graph addEdge" << std::endl;
        throw std::runtime_error("Test failed");
    }

    std::vector<char> dfsResult = charGraph.dfs();
    if (dfsResult != std::vector<char>{'A', 'B', 'C'})
    {
        std::cerr << "Error: Graph DFS (Actual: ";
        for (char c : dfsResult)
        {
            std::cerr << c << " ";
        }
        std::cerr << ", Expected: A B C)" << std::endl;
        throw std::runtime_error("Test failed");
    }

    /*std::vector<char> bfsResult = charGraph.bfs('A');
        if (bfsResult != std::vector<char>{'A', 'B', 'C'})
        {
            std::cerr << "Error: Graph BFS (Actual: ";
            for (char c : bfsResult)
            {
                std::cerr << c << " ";
            }
            std::cerr << ", Expected: A B C)" << std::endl;
            throw std::runtime_error("Test failed");
        }*/
}

int main()
{
    try
    {
        testVertex();
        testEdge();
        testGraph();
        testGraphTraversal();

        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Tests failed: " << e.what() << std::endl;
        return 1;
    }
}
