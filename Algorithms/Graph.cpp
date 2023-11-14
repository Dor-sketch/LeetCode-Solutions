#include "Graph.hpp"
#include <queue>
#include <set>
#include <unordered_set>

// using initializer list is more efficient than using assignment in constructor
// because it directly calls the copy constructor of the member variable
// instead of calling the default constructor and then the assignment operator
Graph::Graph(std::vector<std::vector<std::pair<int, int>>> adjLists_)
    : adjLists_(adjLists_), V_(adjLists_.size()) {}

Graph::Graph(int n) : V_(n) { adjLists_.resize(n); }

Graph::~Graph() {}

void Graph::addEdge(int u, int v, int w) {
    adjLists_[u].push_back(std::make_pair(v, w));
}

// text only
void Graph::printGraph() {
    std::cout << "node | edges" << std::endl;
    for (int i = 0; i < V_; i++) {
        std::cout << "(" << i << ") ";
        bool firstEdge = true;
        for (const auto &edge : adjLists_[i]) {
            if (!firstEdge) {
                std::cout << " | ";
            }
            std::cout << "---" << edge.second << "--->(" << edge.first << ")";
            firstEdge = false;
        }
        std::cout << std::endl;
    }
}

// visual representing
void Graph::printGraphLevels(const std::vector<int> &levels) {
    int max_level = *std::max_element(levels.begin(), levels.end());
    for (int level = 0; level <= max_level; ++level) {
        int indent = (1 << (max_level - level)) - 1; // Using bitwise shift
        bool firstNode = true;
        for (int i = 0; i < V_; ++i) {
            if (levels[i] == level) {
                if (firstNode) {
                    std::cout << std::string(indent * 4, ' ') << i;
                    firstNode = false;
                } else {
                    indent = (1 << (max_level - level + 1)) -
                             1; // Using bitwise shift
                    std::cout << std::string(indent * 4, ' ') << i;
                }
            }
        }
        std::cout << std::endl;
    }
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(V_, false);
    DFSUtil(startVertex, visited);
}

void Graph::DFSUtil(int vertex, std::vector<bool> &visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

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
    std::vector<int> levels(V_, -1);
    std::vector<bool> visited(V_, false);
    std::queue<int> q;

    q.push(s);
    visited[s] = true;
    levels[s] = 0;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        for (const auto &edge : adjLists_[cur_node]) {
            int adjLists_node = edge.first;

            if (!visited[adjLists_node]) {
                visited[adjLists_node] = true;
                q.push(adjLists_node);
                levels[adjLists_node] = levels[cur_node] + 1;
            }
        }
    }
    printGraphLevels(levels);
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

    // print the calculated shortest distances
    std::cout << "Vertex Distance from Source " << s << std::endl;
    for (int i = 0; i < V_; ++i) {
        std::cout << i << "\t\t" << distances[i] << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    Graph g(5);
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

    g.printGraph();
    g.BFS(0);
    g.DFS(0);
    g.Dijkstra(0);

    return 0;
}