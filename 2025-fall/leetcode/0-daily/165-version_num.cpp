#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int compareVersion(string version1, string version2) {
        vector<int> num1, num2;
        int         temp = 0;
        for (auto ch : version1) {
            if (ch == '.') {
                num1.push_back(temp);
                temp = 0;
            } else {
                temp = temp * 10 + (ch - '0');
            }
        }
        num1.push_back(temp);
        temp = 0;
        for (auto ch : version2) {
            if (ch == '.') {
                num2.push_back(temp);
                temp = 0;
            } else {
                temp = temp * 10 + (ch - '0');
            }
        }
        num2.push_back(temp);
        int sz1 = num1.size();
        int sz2 = num2.size();
        int sz = min(sz1, sz2);
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (num1[i] > num2[i]) {
                ans = 1;
                break;
            }
            if (num1[i] < num2[i]) {
                ans = -1;
                break;
            }
        }
        if (ans == 0) {
            int tmp_sz = max(sz1, sz2);
            if (sz1 == tmp_sz)
                for (int i = sz; i < tmp_sz; i++) {
                    if (num1[i] > 0) {
                        ans = 1;
                        break;
                    }
                }
            else if (sz2 == tmp_sz)
                for (int i = sz; i < tmp_sz; i++) {
                    if (num2[i] > 0) {
                        ans = -1;
                        break;
                    }
                }
        }
        return ans;
    }
};