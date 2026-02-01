#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class RideSharingSystem {
private:
    queue<int> riderQueue;
    queue<int> driverQueue;
    unordered_set<int> cancelledRiders;
    unordered_set<int> activeRiders;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        riderQueue.push(riderId);
        activeRiders.insert(riderId);
    }

    void addDriver(int driverId) {
        driverQueue.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        while (!riderQueue.empty() &&
               cancelledRiders.count(riderQueue.front())) {
            activeRiders.erase(riderQueue.front());
            riderQueue.pop();
        }

        if (riderQueue.empty() || driverQueue.empty()) {
            return {-1, -1};
        }

        int driverId = driverQueue.front();
        driverQueue.pop();

        int riderId = riderQueue.front();
        riderQueue.pop();
        activeRiders.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        if (activeRiders.count(riderId)) {
            cancelledRiders.insert(riderId);
        }
    }
};
