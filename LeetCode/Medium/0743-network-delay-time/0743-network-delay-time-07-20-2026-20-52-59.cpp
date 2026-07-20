class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Create adjacency list
        vector<pair<int, int>> adj[n + 1];

        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            int currentDistance = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if (currentDistance > dist[u]) {
                continue;
            }

            for (auto neighbour : adj[u]) {

                int v = neighbour.first;
                int weight = neighbour.second;

                if (dist[v] > dist[u] + weight) {

                    dist[v] = dist[u] + weight;

                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};