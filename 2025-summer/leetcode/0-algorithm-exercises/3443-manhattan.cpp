// 贪心算法 - 每一步看一下当前最大值
#include <string>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int maxDistance(string s, int k) {
        int sz = s.size();
        int N = 0, S = 0, W = 0, E = 0;
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'N') N++;
            if (s[i] == 'S') S++;
            if (s[i] == 'E') E++;
            if (s[i] == 'W') W++;
            int d1 = max(N,S) + max(W,E);
            int d2 = min(N,S) + min(W,E);
            int d = d1 + (d2<k?d2:2*k-d2); // 每一步都看一下
            ans = max(ans,d); // 去最大即可
        }
        return ans; // 注意要在循环内取最大值。
    }
};