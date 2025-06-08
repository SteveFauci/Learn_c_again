#include <string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int minimumRecolors(string blocks, int k) {
        auto size = blocks.size();
        int current = 0,ans = 0;
        for (int i = 0; i < size; i++) {
            if(blocks[i] == 'B')current++;
            if(i<k-1)continue;
            ans = max(current,ans);
            if(ans==k)break;
            if(blocks[i-k+1] == 'B')current--;
        }
        return k-ans;
    }
};