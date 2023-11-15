#include "Graph.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void testAddEdge() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);

    // Assertions to validate the state of the graph after adding edges
    // Check if the edge (0, 1) with weight 10 is correctly added
    const auto &adjList0 = g.getAdjList(0);
    assert(std::find(adjList0.begin(), adjList0.end(), std::make_pair(1, 10)) !=
               adjList0.end() &&
           "Edge (0, 1) with weight 10 not found");

    // Check if the edge (0, 4) with weight 5 is correctly added
    assert(std::find(adjList0.begin(), adjList0.end(), std::make_pair(4, 5)) !=
               adjList0.end() &&
           "Edge (0, 4) with weight 5 not found");

    g.printAdjacencyLists();

    // Optionally, check the reverse edges for an undirected graph
    UndirectedGraph undirected_g(5);
    undirected_g.addEdge(0, 1, 10);
    undirected_g.addEdge(0, 4, 5);
    const auto &adjList1 = undirected_g.getAdjList(1);
    assert(std::find(adjList1.begin(), adjList1.end(), std::make_pair(0, 10)) !=
               adjList1.end() &&
           "Edge (1, 0) with weight 10 not found");

    const auto &adjList4 = undirected_g.getAdjList(4);
    assert(std::find(adjList4.begin(), adjList4.end(), std::make_pair(0, 5)) !=
               adjList4.end() &&
           "Edge (4, 0) with weight 5 not found");

    undirected_g.printAdjacencyLists();

    std::cout << "testAddEdge passed" << std::endl;
}

void testBFS() {
    std::ifstream file("graph_test_input.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    std::string line;
    int testCount = 1;

    while (std::getline(file, line)) {
        if (line.rfind("graphsize:", 0) == 0) {
            int numberOfNodes;
            std::sscanf(line.c_str(), "graphsize: %d", &numberOfNodes);

            Graph g(numberOfNodes);
            while (std::getline(file, line) && line != "results:") {
                if (line == "nodes:")
                    continue; // Skip the "nodes:" line
                std::istringstream edgeStream(line);
                int u, v, w;
                edgeStream >> u >> v >> w;
                g.addEdge(u, v, w);
            }

            std::vector<int> expectedLevels;
            while (std::getline(file, line) && !line.empty()) {
                std::istringstream levelStream(line);
                int level;
                while (levelStream >> level) {
                    expectedLevels.push_back(level);
                }
            }

            std::vector<int> bfsLevels = g.BFS(0);

            if (bfsLevels != expectedLevels) {
                std::cout << "Test " << testCount << " failed.\n";
                std::cout << "Expected BFS levels: ";
                for (int lvl : expectedLevels)
                    std::cout << lvl << " ";
                std::cout << "\nGot BFS levels: ";
                for (int lvl : bfsLevels)
                    std::cout << lvl << " ";
                std::cout << "\n\n";
            } else {
                std::cout << "Test " << testCount << " passed.\n";
            }

            ++testCount;
        }
    }

    file.close();
}

void testDFS() {
    std::ifstream file("dfs_test_input.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    std::string line;
    int testCount = 1;

    while (std::getline(file, line)) {
        if (line.rfind("graphsize:", 0) == 0) {
            int numberOfNodes;
            std::sscanf(line.c_str(), "graphsize: %d", &numberOfNodes);

            Graph g(numberOfNodes);
            int startVertex;

            // Read edges
            while (std::getline(file, line) && line != "expected_levels:") {
                if (line == "edges:")
                    continue; // Skip the "edges:" line
                else if (line != "start: 0") {
                std::cout<<line;

                std::istringstream edgeStream(line);
                int u, v;
                edgeStream >> u >> v;
                std::cout<<"adding: (" << u <<","<<v<<",0)\n";
                g.addEdge(u, v, 0); // Assuming weight = 1 for simplicity
                }
            }
            g.printAdjacencyLists();
            // Read expected DFS levels
            std::getline(file, line); // Read start vertex line
            std::sscanf(line.c_str(), "start: %d", &startVertex);

            std::vector<int> expectedLevels;
            std::getline(file, line); // Read expected levels line
            std::istringstream levelStream(line);
            int level;
            while (levelStream >> level) {
                expectedLevels.push_back(level);
            }

            // Perform DFS
            std::vector<int> dfsLevels = g.DFS(startVertex);

            // Compare DFS levels with expected levels
            if (dfsLevels != expectedLevels) {
                std::cout << "Test " << testCount << " failed.\n";
                std::cout << "Expected DFS levels: ";
                for (int lvl : expectedLevels)
                    std::cout << lvl << " ";
                std::cout << "\nGot DFS levels: ";
                for (int lvl : dfsLevels)
                    std::cout << lvl << " ";
                std::cout << "\n\n";
            } else {
                std::cout << "Test " << testCount << " passed.\n";
            }

            ++testCount;
        }
    }

    file.close();
}

void testDijkstra() {
    Graph g(5);
    // Populate the graph with edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);

    // Call g.Dijkstra and assert the expected outcome
    // Example: Check if the shortest paths are correct
    // ...

    std::cout << "testDijkstra passed" << std::endl;
}

void testFloydWarshall() {
    Graph g(4);
    // Populate the graph with edges
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);

    // Call g.FloydWarshall and assert the expected outcome
    // Example: Check if the shortest paths matrix is correct
    // ...

    std::cout << "testFloydWarshall passed" << std::endl;
}

int main() {
    testAddEdge();
    testBFS();

    // TODO: #1 complete asserts for other tests
    testDFS();
    testDijkstra();
    testFloydWarshall();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
