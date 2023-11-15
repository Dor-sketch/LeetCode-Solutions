#include "Graph.hpp"
#include "TreeVisualizer.hpp"
#include <iomanip>

// Define color for the node
constexpr char YELLOW[] = "\033[1;33m";
constexpr char RESET[] = "\033[0m";
constexpr char OPEN_BRACES[] = "\033[1m\033[1;32m(";
constexpr char CLOSE_BRACES[] = ")\033[0m ";
constexpr char START_ARROW[] = "\033[1;33m---";
constexpr char RESET_ARROW[] = "---►\033[0m";
constexpr char LONG_ARROW[] = "\033[1;33m------►\033[0m";

// using initializer list is more efficient than using assignment in
// constructor because it directly calls the copy constructor of the member
// variable instead of calling the default constructor and then the
// assignment operator
Graph::Graph(std::vector<std::vector<std::pair<int, int>>> adjLists_)
    : adjLists_(adjLists_), V_(adjLists_.size()) {}

Graph::Graph(int n) : V_(n) { adjLists_.resize(n); }

Graph::~Graph() {}

void Graph::addEdge(int u, int v, int w) {
    adjLists_[u].push_back(std::make_pair(v, w));
}

void Graph::printAdjacencyLists() {
    std::cout
        << "\033[1;32mNode\033[0m | \033[1;34mEdges\033[0m\n"; // Using ANSI
                                                               // color codes
    for (int i = 0; i < V_; i++) {
        std::cout << OPEN_BRACES << i << CLOSE_BRACES;
        bool firstEdge = true;
        for (const auto &edge : adjLists_[i]) {
            if (!firstEdge) {
                std::cout << " | ";
            }
            std::cout << START_ARROW << std::setw(2) << edge.second
                      << RESET_ARROW << OPEN_BRACES << edge.first
                      << CLOSE_BRACES;
            firstEdge = false;
        }
        std::cout << std::endl;
    }
}

// ============ Algorithms ===============

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(V_, false);
    DFSUtil(startVertex, visited);
    std::cout << std::endl;
}

void Graph::DFSUtil(int vertex, std::vector<bool> &visited) {
    visited[vertex] = true;
    std::cout << LONG_ARROW << OPEN_BRACES << vertex << CLOSE_BRACES;

    // Iterate through each pair (neighbor, weight) in the adjacency list of the
    // current vertex
    for (const auto &adjVertex : adjLists_[vertex]) {
        int neighbor =
            adjVertex.first; // Extract the neighbor vertex from the pair
        if (!visited[neighbor]) {
            DFSUtil(neighbor,
                    visited); // Recursive call with the neighbor vertex
        }
    }
}

// sort nodes by number of edges from s
// for unweighted graph, this is the shortest path from s to other nodes
void Graph::BFS(int s) {

    std::vector<TreeVisualizer::NodeInfo> shortest_path(V_);
    std::vector<bool> visited(V_, false);
    std::queue<int> q;

    q.push(s);
    visited[s] = true;
    shortest_path[s] = {0, s};

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        for (const auto &edge : adjLists_[cur_node]) {
            int adjLists_node = edge.first;

            if (!visited[adjLists_node]) {
                visited[adjLists_node] = true;
                q.push(adjLists_node);
                // updating to track paths in addition to weights
                shortest_path[adjLists_node].parent = cur_node;
                shortest_path[adjLists_node].level =
                    (shortest_path[cur_node].level + 1);
            }
        }
    }

    TreeVisualizer visualizer(shortest_path);
    visualizer.visualizeTree();
}

// for weighted graph, this is the shortest path from s to other nodes
void Graph::Dijkstra(int s) {

    std::vector<int> distances(V_, std::numeric_limits<int>::max());
    std::unordered_set<int> visited;
    std::set<std::pair<int, int>> pq; // Pair of distance and node ID
    distances[s] = 0;
    pq.insert({0, s});

    while (!pq.empty()) {
        int current_node = pq.begin()->second;

        pq.erase(pq.begin());

        if (visited.find(current_node) != visited.end()) {
            continue;
        }
        visited.insert(current_node);
        for (const auto &neighbor : adjLists_.at(current_node)) {
            int next_node = neighbor.first; // Neighbor node ID
            int next_distance = distances[current_node] + neighbor.second;

            if (next_distance < distances[next_node]) {
                pq.erase({distances[next_node], next_node});
                distances[next_node] = next_distance;
                pq.insert({next_distance, next_node});
            }
        }
    }

    std::cout << OPEN_BRACES << s << CLOSE_BRACES;

    // print the calculated shortest distances
    for (int i = 0; i < V_; ++i) {
        std::cout << START_ARROW << std::setw(2) << distances[i] << RESET_ARROW
                  << OPEN_BRACES << i << CLOSE_BRACES;
    }

    std::cout << std::endl;
}

void Graph::FloydWarshall() {
    // Initialize the solution matrix
    std::vector<std::vector<int>> dist(
        V_, std::vector<int>(V_, std::numeric_limits<int>::max()));

    // Set distance from each vertex to itself as 0
    for (int i = 0; i < V_; ++i) {
        dist[i][i] = 0;
    }

    // Initialize with given graph's edges
    for (int i = 0; i < V_; ++i) {
        for (const auto &neighbor : adjLists_[i]) {
            dist[i][neighbor.first] = neighbor.second;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V_; ++k) {
        for (int i = 0; i < V_; ++i) {
            for (int j = 0; j < V_; ++j) {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max()) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distances
    for (size_t i = 0; i < dist.size(); ++i) {
        const auto &row = dist[i];
        std::cout << "Row " << OPEN_BRACES << i << CLOSE_BRACES << LONG_ARROW
                  << "| ";
        for (const auto &elem : row) {
            std::cout << YELLOW << std::setw(2) << elem << RESET << " ";
        }
        std::cout << "|" << std::endl;
    }

    // Add a check for negative weight cycles (optional)
}

int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 2, 6);
    g.addEdge(3, 0, 7);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

    g.printAdjacencyLists();

    std::cout << "BFS" << std::endl;
    g.BFS(0);
    std::cout << std::endl;

    std::cout << "DFS" << std::endl;
    for (int i = 0; i < V; ++i)
        g.DFS(i);

    std::cout << "Dijkstra" << std::endl;
    for (int i = 0; i < V; ++i)
        g.Dijkstra(i);

    std::cout << "FloydWarshall" << std::endl;
    g.FloydWarshall();

    return 0;
}