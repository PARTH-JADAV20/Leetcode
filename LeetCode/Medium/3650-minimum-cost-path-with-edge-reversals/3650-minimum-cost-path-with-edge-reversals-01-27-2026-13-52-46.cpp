class Solution {
public:
    struct Pair {
        int x;
        long long c;
        Pair(int x, long long c) : x(x), c(c) {}
    };

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n), rev(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;
            if (u == n - 1) return (int)dist[u];

            for (auto &[v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }

            for (auto &[v, w] : rev[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};