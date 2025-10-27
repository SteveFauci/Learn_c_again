#include <vector>
using namespace std;
class Solution {
  public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& t : trips) {
            int num = t[0], from = t[1], to = t[2];
            d[from] += num;
            d[to] -= num;
        }
        int s = 0;
        for (int v : d) {
            s += v;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};
class Solution0 {
  public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1005, 0);
        for (auto t : trips) {
            int from = t[1], to = t[2], p = t[0];
            for (int i = from; i < to; i++) {
                road[i] += p;
                if (road[i] > capacity)
                    return false;
            }
        }
        return true;
    }
};
