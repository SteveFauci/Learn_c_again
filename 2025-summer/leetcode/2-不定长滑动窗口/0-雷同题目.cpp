#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

//1695
class Solution1695 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sz = nums.size();
        int left = 0;
        unordered_map<int, int> my_map;
        int temp = 0;
        int ans = 0;
        for (int right = 0; right < sz; right++) {
            temp += nums[right];
            my_map[nums[right]]++;
            while (my_map[nums[right]] > 1) {
                my_map[nums[left]]--;
                temp -= nums[left];
                left++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};

// 2958
class Solution2958 {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int sz = nums.size();
        int left = 0;
        unordered_map<int,int> my_map;
        int ans = 0;
        for(int right = 0; right < sz; right++){
            my_map[nums[right]]++;
            while(my_map[nums[right]]>k){
                my_map[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// 2024
class Solution2024 {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int sz = answerKey.size();
        int ans = 0, left = 0, Ts = 0, Fs = 0;
        for(int right = 0; right < sz; right++){
            if(answerKey[right]=='T')Ts++;
            if(answerKey[right]=='F')Fs++;
            while((Ts > k) + (Fs > k) == 2){
                if(answerKey[left]=='T')Ts--;
                if(answerKey[left]=='F')Fs--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// 1004
class Solution1004 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sz = nums.size();
        int my_map[2] = {0};
        int left = 0, ans = 0;
        for (int right = 0; right < sz; right++) {
            my_map[nums[right]]++;
            while (my_map[0] > k) {
                my_map[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// 1658
class Solution1658 {
public:
    int minOperations(vector<int>& nums, int x) {
        int sz = nums.size();
        int sum = 0, left = 0, ans = -1;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
        }
        if (sum < x) return -1;
        int key = sum - x;
        sum = 0;
        for (int right = 0; right < sz; right++) {
            sum += nums[right];
            while (sum > key) {
                sum -= nums[left];
                left++;
            }
            if (sum == key)
                ans = max(ans, right - left + 1);
        }
        return ans == -1 ? -1 : sz - ans;
    }
};