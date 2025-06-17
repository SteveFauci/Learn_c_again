#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        auto len = s.size();
        for(int i =0;i<len/2;i++){
            swap(s[i],s[len-1-i]);
        }
    }
    void swap(char&a,char&b){
        char c = a;
        a = b;
        b = c;
    }
};