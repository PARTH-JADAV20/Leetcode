class AuctionSystem {
    unordered_map<int, unordered_map<int, int>> m;
    unordered_map<int, set<pair<int, int>>> q;

public:
    void addBid(int u, int i, int a) {
        if (m[i].count(u)) q[i].erase({m[i][u], u});
        m[i][u] = a;
        q[i].insert({a, u});
    }

    void updateBid(int u, int i, int a) { addBid(u, i, a); }

    void removeBid(int u, int i) {
        q[i].erase({m[i][u], u});
        m[i].erase(u);
    }

    int getHighestBidder(int i) { return q[i].empty() ? -1 : q[i].rbegin()->second; }
};