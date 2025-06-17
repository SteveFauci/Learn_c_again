#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto sz = prices.size();
        int min_n = prices[0];
        int gain = 0;
        for (int i = 0; i < sz; i++) {
            min_n = min(min_n, prices[i]);
            gain = max(gain, prices[i] - min_n);
        }
        return gain;
    }
};