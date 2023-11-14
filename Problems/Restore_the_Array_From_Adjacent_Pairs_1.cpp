class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, unordered_set<int>> adj; // Map to store adjacency list
        for (auto& p : adjacentPairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }

        int n = adjacentPairs.size() + 1;
        vector<int> restoredArray(n);
        int start;

        // Find start (an element with only one adjacent element)
        for (auto& p : adj) {
            if (p.second.size() == 1) {
                start = p.first;
                break;
            }
        }

        // Reconstruct the array
        int prev = start, curr;
        for (int i = 0; i < n; ++i) {
            restoredArray[i] = prev;
            // Next element is the adjacent not equal to the previous
            for (int next : adj[prev]) {
                if (i == 0 || next != restoredArray[i - 1]) {
                    curr = next;
                    break;
                }
            }
            prev = curr;
        }
        return restoredArray;
    }
};