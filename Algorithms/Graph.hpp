#pragma once

#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <vector>

class Graph {
  public:
    Graph(std::vector<std::vector<std::pair<int, int>>> adj);
    Graph(int n);
    ~Graph();

    // Utility
    void addEdge(int u, int v, int w);
    void printGraph();
    void printGraphLevels(const std::vector<int> &levels);

    // Algorithms
    void BFS(int s);
    void DFS(int s); // to init the DFS
    void Dijkstra(int s);
    void BellmanFord(int s);
    // void FloydWarshall();
    // void Prim();
    // void Kruskal();
    // void TopologicalSort();
    // void TopologicalSortUtil(int s, bool visited[], stack<int> &Stack);
    // void SCC();
    // void SCCUtil(int s, int disc[], int low[], stack<int> *st, bool
    // stackMember[]);
    // void HamiltonianCycle();
    // void HamiltonianCycleUtil(int path[], int pos, bool visited[]);
    // void HamiltonianPath();
    // void HamiltonianPathUtil(int path[],int pos, bool visited[]);
    // void EulerianCycle();
    // void EulerianCycleUtil(int s, list<int> *adj, int V, int E);
    // void EulerianPath();
    // void EulerianPathUtil(int s, list<int> *adj, int V, int E);
    // void Coloring();

  private:
    // each vertex (node) has a vector of pairs storing its neighbors (dest
    // node, weight)
    std::vector<std::vector<std::pair<int, int>>> adjLists_;
    int V_;

    void DFSUtil(int vertex, std::vector<bool> &visited);
};