#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(arr[mid] < arr[mid + 1]) l = mid + 1;
            if(arr[mid] > arr[mid + 1]) r = mid - 1;
        }
        return mid;
    }
};