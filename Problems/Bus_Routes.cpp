class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);
        unordered_map<int, int> visited;
        visited[source] = 0;
        vector<bool> visitedRoutes(routes.size(), false);

        while (!q.empty()) {
            int currentStop = q.front();
            q.pop();

            for (int i : stopToRoutes[currentStop]) {
                if (visitedRoutes[i]) continue;
                visitedRoutes[i] = true;

                for (int stop : routes[i]) {
                    if (visited.count(stop) == 0) {
                        visited[stop] = visited[currentStop] + 1;
                        q.push(stop);
                        if (stop == target) return visited[stop];
                    }
                }
            }
        }

        return -1; // No path found
    }
};
