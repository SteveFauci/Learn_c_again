// 卡了越界访问的bug没想到过了(Line10)。。
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp;
        int    nums = strs.size();
        int    leng = strs[0].length(); //这里leng换成最短的strs[i].length()就好了
        char   ch;

        for (int i = 0; i < leng; i++) {     // 每个句子第i个字符
            ch = strs[0][i];                 // 第0个句子的第i个字符
            int flag = 0;
            for (int j = 0; j < nums; j++) { // 第j个句子的第i个字符
                if(strs[j][i]!=ch){flag = 1;break;}
            }
            if(flag == 1)break;
            else temp+=ch;
        }
        return temp;
    }
};