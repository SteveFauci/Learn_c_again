#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int size = numbers.size();
        int front = 0, back = size - 1;
        int current = numbers[front] + numbers[back];
        while (current != target) {
            if (current > target) back--;
            else if (current < target) front++;
            current = numbers[front] + numbers[back];
        }
        ans[0] = front + 1;
        ans[1] = back + 1;
        return ans;
    }
};