#include <unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sz = fruits.size();
        int left = 0;
        int ans = 0;
        unordered_map<int, int> my_map;
        for(int right = 0; right < sz; right++){
            my_map[fruits[right]]++;
            while(my_map.size()>2){
                my_map[fruits[left]]--;
                if(my_map[fruits[left]]==0)my_map.erase(fruits[left]);
                left++;
            }
            ans = max(ans,right - left +1);
        }
        return ans;
    }
};