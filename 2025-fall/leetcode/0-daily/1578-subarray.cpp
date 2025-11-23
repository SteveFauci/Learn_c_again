#include <numeric>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int slow = 0, fast = 1;
        int n = colors.size();
        int ans = 0;
        while(fast < n){
            int curmax = time[slow];
            int cursum = time[slow];
            while(colors[fast] == colors[slow] && fast < n){
                curmax = max(curmax, time[fast]);
                cursum += time[fast];
                fast++;
            }
            if(fast - slow > 1)
                ans = ans + cursum - curmax;
            slow = fast;
        }
        return ans;
    }
};
class Solution0 {
public:
    int minCost(string colors, vector<int>& time) {
        int slow = 0, fast = 1;
        int n = colors.size();
        int ans = 0;
        while(fast < n){
            while(colors[fast] == colors[slow] && fast < n){
                fast++;
            }
            vector<int> subarr(time.begin() + slow, time.begin() + fast);
            sort(subarr.begin(),subarr.end());
            int cursum = accumulate(subarr.begin(), subarr.end(),0);
            cursum -= subarr[subarr.size() - 1];
            ans += cursum;
            slow = fast;
        }
        return ans;
    }
};