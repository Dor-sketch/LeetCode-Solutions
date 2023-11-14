class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, unordered_set<int>> adj; // Map with sets for adjacency
    
        // Build the adjacency list
        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);
        }
    
        // Find the starting element (with only one adjacent element)
        int start;
        for (const auto& p : adj) {
            if (p.second.size() == 1) {
                start = p.first;
                break;
            }
        }
    
        // Reconstruct the array
        vector<int> restoredArray;
        int current = start;
        int previous = -1; // A value that's not in the array
    
        while (restoredArray.size() < adj.size()) {
            restoredArray.push_back(current);
            for (int next : adj[current]) {
                if (next != previous) {
                    previous = current;
                    current = next;
                    break;
                }
            }
        }
    
        return restoredArray;
    }
};