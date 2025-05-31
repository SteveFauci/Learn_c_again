/*
f(n)=f(n-1)+f(n-2)
n个台阶不管什么走法，最后一步要么是走1个台阶，要么是走2个台阶。
最后一步是1个台阶的话，前面n-1个台阶有f(n-1)种走法，
最后一步是2个台阶的话，前面n-2个台阶有f(n-2)种走法，
∴f(n)=f(n-1)+f(n-2)
*/
#include <vector>
using namespace std;
class Solution {
  public:
    int climbStairs(int n) {
        vector<int> arr{0,1,1};
        for (int i = 3; i <= n; i++) {
            arr.push_back(arr[i-2]+arr[i-1]);
        }
        return arr.at(n);
    }
};