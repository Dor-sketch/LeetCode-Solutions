#include "Graph.hpp"
#include <iomanip>
#include <queue>

// Define color for the node
constexpr char YELLOW[] = "\033[1;33m";
constexpr char RESET[] = "\033[0m";
constexpr char OPEN_BRACES[] = "\033[1m\033[1;32m(";
constexpr char CLOSE_BRACES[] = ")\033[0m ";
constexpr char START_ARROW[] = "\033[1;33m---";
constexpr char RESET_ARROW[] = "---►\033[0m";
constexpr char LONG_ARROW[] = "\033[1;33m------►\033[0m";
constexpr char ADJ_LIST_TITLE[] =
    "\033[1;32mNode\033[0m | \033[1;34mEdges\033[0m\n";

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
    std::cout << ADJ_LIST_TITLE;
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

std::vector<int> Graph::DFS(int startVertex) {
    std::vector<TreeVisualizer::NodeInfo> dfsInfo(
        V_, {-1, -1}); // Initialize parent and depth as -1
    std::vector<bool> visited(V_, false);

    DFSUtil(startVertex, 0, 0, visited, dfsInfo);

    // Optionally visualize the tree
    TreeVisualizer visualizer(dfsInfo);
    visualizer.visualizeTree();

    // Extract levels from shortest_path and return
    std::vector<int> levels;
    for (int i = 0; i < V_; ++i) {
        if (dfsInfo[i].parent != -1 || i == startVertex) {
            // Node is reachable, so add its level to the vector
            levels.push_back(dfsInfo[i].level);
        }
    }

    return levels;
}

void Graph::DFSUtil(int vertex, int parent, int depth,
                    std::vector<bool> &visited,
                    std::vector<TreeVisualizer::NodeInfo> &dfsInfo) {
    visited[vertex] = true;
    dfsInfo[vertex] = {parent, depth}; // Store parent and depth information

    // Iterate through each neighbor
    for (const auto &adjVertex : adjLists_[vertex]) {
        int neighbor = adjVertex.first;
        if (!visited[neighbor]) {
            DFSUtil(neighbor, vertex, depth + 1, visited, dfsInfo);
        }
    }
}

// sort nodes by number of edges from s
// for unweighted graph, this is the shortest path from s to other nodes
std::vector<int> Graph::BFS(int s) {
    // Perform BFS traversal
    auto shortest_path = BFSUtil(s);

    // Visualize tree
    TreeVisualizer visualizer(shortest_path);
    visualizer.visualizeTree();

    // Extract levels from shortest_path and return
    std::vector<int> levels;
    for (int i = 0; i < V_; ++i) {
        if (shortest_path[i].parent != -1 || i == s) {
            // Node is reachable, so add its level to the vector
            levels.push_back(shortest_path[i].level);
        }
    }

    return levels;
}

std::vector<TreeVisualizer::NodeInfo> Graph::BFSUtil(int s) {

    std::vector<TreeVisualizer::NodeInfo> shortest_path(V_);
    std::vector<bool> visited(V_, false);
    std::queue<int> q;

    for (auto &node : shortest_path) {
        node.parent = -1;
        node.level = -1;
    }

    q.push(s);
    visited[s] = true;
    shortest_path[s] = {0, -1};

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
    return shortest_path;
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

// for graphs whith nagative edges
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

void UndirectedGraph::addEdge(int u, int v, int w) {
    adjLists_[u].push_back(std::make_pair(v, w));
    adjLists_[v].push_back(std::make_pair(u, w));
}
