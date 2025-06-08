#include <vector>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int thr = k*threshold;
        auto size = arr.size();
        int sum = 0,cnt=0;
        for(int i =0;i<size;i++){
            sum+=arr[i];
            if(i<k-1)continue;
            if(sum>=thr)cnt++;
            sum-=arr[i-k+1];
        }
        return cnt;
    }
};