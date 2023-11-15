#pragma once

#include "TreeVisualizer.hpp"
#include <vector>

class Graph {
  public:
    Graph(std::vector<std::vector<std::pair<int, int>>> adj);
    Graph(int n);
    virtual ~Graph();

    // Utility
    virtual void addEdge(int u, int v, int w);
    void printAdjacencyLists();
    // Method to access the adjacency list for testing
    const std::vector<std::pair<int, int>> &getAdjList(int u) const {
        return adjLists_[u];
    }

    // Search algorithms

    // handles the visualization and returning of levels
    std::vector<int> BFS(int s);
    void DFS(int s); // to init the DFS

    // Shortest path
    void BellmanFord(int s);
    void Dijkstra(int s);
    void FloydWarshall();

  protected:
    std::vector<std::vector<std::pair<int, int>>> adjLists_;

  private:
    int V_;

    // for the BFS traversal and storing levels.
    std::vector<TreeVisualizer::NodeInfo> BFSUtil(int s);
    void DFSUtil(int vertex, std::vector<bool> &visited);
};

class UndirectedGraph : public Graph {

  public:
    UndirectedGraph(int V) : Graph(V) {}
    void addEdge(int u, int v, int w) override;

    // Minimum spaning tree
    void Kruskal();
    void Prim();
};