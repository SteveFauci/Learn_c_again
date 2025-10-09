#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int my_search(int cur_spell,vector<int> &potions, int success){
        int index = potions.size();
        int l = 0, r = index - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if((long long)cur_spell * potions[mid] >= success){
                r = mid - 1;
                index = mid;
            }else{
                l = mid + 1;
            }
        }
        return index;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int sz = potions.size();
        vector<int> ans(n);
        int index = 0;
        for(int i = 0; i < n; i++){
            index = my_search(spells[i], potions,success);
            ans[i] = index;
        }
        return ans;
    }
};