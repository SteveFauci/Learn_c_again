#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int sz = s.size();
        string temp;
        vector<string> ans;
        while(sz%k){s+=fill;sz = s.size();}
        for(int i = 0;i < sz; i+=k){
            for(int j = 0; j < k; j++){temp+=s[i+j];}
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};