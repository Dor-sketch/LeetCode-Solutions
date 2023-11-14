
struct GraphNode {
    std::vector<std::pair<int, int>> neighbors; // Pair of neighbor ID and cost
};


class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        // Initialize all nodes
        for (int i = 0; i < n; ++i) {
            nodes_[i] = GraphNode();
        }

        // Add edges
        for (const auto& edge : edges) {
            addEdge(edge);
        }
    }

    void addEdge(const std::vector<int>& edge) {
        int from = edge[0], to = edge[1], cost = edge[2];
        nodes_[from].neighbors.emplace_back(to, cost);
    }
    
int shortestPath(int node1, int node2) {

    std::vector<int> distances(nodes_.size(), std::numeric_limits<int>::max());
    std::unordered_set<int> visited;
    std::set<std::pair<int, int>> pq;  // Pair of distance and node ID

    distances[node1] = 0;
    pq.insert({0, node1});

    while (!pq.empty()) {
        int current_node = pq.begin()->second;

        if (current_node==node2)
            return distances[node2];
        
        pq.erase(pq.begin());

        if (visited.find(current_node) != visited.end()) {
            continue;
        }
        visited.insert(current_node);

        for (const auto& neighbor : nodes_.at(current_node).neighbors) {
            int next_node = neighbor.first;
            int next_distance = distances[current_node] + neighbor.second;

            if (next_distance < distances[next_node]) {
                pq.erase({distances[next_node], next_node});
                distances[next_node] = next_distance;
                pq.insert({next_distance, next_node});
            }
        }
    }

    return distances[node2] == std::numeric_limits<int>::max() ? -1 : distances[node2];
}



private:
    std::unordered_map<int, GraphNode> nodes_;
};


/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */