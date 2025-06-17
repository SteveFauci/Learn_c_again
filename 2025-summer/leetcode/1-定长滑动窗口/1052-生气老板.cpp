#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sz = customers.size();
        int ans = 0, total = 0;
        for(int i = 0; i < sz; i++){
            if(!grumpy[i])total+=customers[i];
        }
        for(int i = 0; i < sz; i++){
            if(grumpy[i])total += customers[i];
            if(i < minutes - 1)continue;
            ans = max(ans,total);
            if(grumpy[i-minutes+1])total -= customers[i-minutes+1];
        }
        return ans;
    }
};