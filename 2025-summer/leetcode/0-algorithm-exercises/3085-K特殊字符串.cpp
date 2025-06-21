#include <string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
  public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26,0);
        int sz = word.size();
        for (int i = 0; i < sz; i++) {
            cnt[word[i]-'a']++;
        }
  //      sort(cnt.begin(),cnt.end(),[](int a,int b){return a>b;});
        int ans = 2147483647;
        int count = 0;
        for(int i = 0; i < 26; i++){ //选cnt[i]为最小的，则 1. 比cnt[i]小的全扔了 2. 比cnt[i]+k大的腰斩。记录减去的数，并取最小的。
            int temp = cnt[i];
            count = 0;
            for(int j = 0; j < 26; j++){
                if(cnt[j] < temp) count += cnt[j];
                else if(cnt[j] >= temp + k) count += cnt[j] - (temp + k);
            }
            ans = min(ans,count);
        }
        return ans;
    }
};