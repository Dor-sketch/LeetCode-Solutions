#include "Graph.hpp"
#include <cassert>
#include <iostream>

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

    std::cout << "testAddEdge passed" << std::endl;
}

void testBFS() {
    Graph g(5);
    // Populate the graph with edges
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    // Expected levels when starting BFS from node 0
    std::vector<int> expectedLevels = {0, 1, 1, 2, 2};

    // Call g.BFS and get the BFS levels
    std::vector<int> bfsLevels = g.BFS(0);

    // Assert the expected levels
    assert(bfsLevels == expectedLevels &&
           "BFS levels do not match expected levels.");

    std::cout << "testBFS passed" << std::endl;
}

void testDFS() {
    Graph g(5);
    // Populate the graph with edges
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    // Call g.DFS and assert the expected outcome
    // Example: Check if the DFS traversal is as expected
    // ...

    std::cout << "testDFS passed" << std::endl;
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
