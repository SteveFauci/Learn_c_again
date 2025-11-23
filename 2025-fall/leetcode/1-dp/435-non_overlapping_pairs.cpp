#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(),[](const vector<int>& a, const vector<int>& b) {
            // if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int curL = inter[0][0], curR = inter[0][1];
        int cnt = 0;
        int n = inter.size();
        for(int j = 1; j < n; j++){
            auto i = inter[j];
            // if(i[0] == curL){cnt++;continue;}
            if(i[0] < curR){cnt++;continue;}
            // else if(i[1] > curL){curL = i[0], curR = i[1];}
        }
        return cnt;
    }
};