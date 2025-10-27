#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int getNum(string& bank){
        int num = 0;
        for(auto ch: bank){
            if(ch == '1')num++;
        }
        return num;
    }
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> bnk(n);
        for(int i = 0; i < n; i++){
            bnk[i] = getNum(bank[i]);
        }
        int pre = 0;
        int sum = 0;
        for(int i = 1; i < n; i++){
            if(!bnk[i])continue;
            sum += bnk[i] * bnk[pre];
            pre = i;
        }
        return sum;
    }
};