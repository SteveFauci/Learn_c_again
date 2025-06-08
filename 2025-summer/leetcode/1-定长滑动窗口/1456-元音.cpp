#include <algorithm>
#include <string>

using namespace std;
// 复杂度O(N*k)，不出意外的超时了
class Solution0 {
  public:
    int maxVowels(string s, int k) {
        auto size = s.length();
        int  ans = 0;
        for (int i = 0; i <= size - k; i++) {
            int curr_length = 0;
            for (int j = 0; j < k; j++) {
                if (isVowels(s[i + j]))
                    curr_length++;
            }
            ans = max(ans, curr_length);
            if (ans == k)
                break;
        }
        return ans;
    }

  private:
    bool isVowels(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};

// 滑动窗口
class Solution {
  public:
    int maxVowels(string s, int k) {
        auto size = s.length();
        int  max_l = 0, current = 0;
        for (int i = 0; i < k; i++) {//构建第一个窗口
            char ch = s[i];
            if (isVowels(ch))
                current++;
        }
        max_l = max(max_l, current);
        for (int i = 1; i <= size - k; i++) {
            if (isVowels(s[i - 1]))//离开的有用减掉
                current--;
            if (isVowels(s[i + k - 1]))//加入的有用加上
                current++;
            max_l = max(max_l, current);
        }
        return max_l;
    }

  private:
    bool isVowels(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};

// 同时构建窗口
class Solution1 {
  public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowels(s[i])) vowel++;     // 1. 进入窗口
            if (i < k - 1) continue;             // 窗口大小不足 k
            ans = max(ans, vowel);          // 2. 更新答案
            char out = s[i - k + 1];             // 3. 离开窗口
            if (isVowels(out)) vowel--;
        }
        return ans;
    }
  private:
    bool isVowels(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};
