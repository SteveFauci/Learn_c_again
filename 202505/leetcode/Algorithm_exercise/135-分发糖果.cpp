#include <vector>
using namespace std;
class Solution {
  public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        int b1[sz], b2[sz], b3[sz];
        for (int i = 0; i < sz; i++) {
            b1[i] = (i == sz - 1) ? 0 : (ratings[i] > ratings[i + 1]);
            b2[i] = (i == 0) ? 0 : ratings[i] > ratings[i - 1];
            b3[i] = b1[i] + b2[i];
        }
        int num[sz]; // 储存糖果数
        for (int i = 0; i < sz; i++) {
            num[i] = 0;
        }

        int flag = -1; // flag标注最小的元素,即两个bool全是0
        // [1,2,1]
        for (int i = 0; i < sz; i++) {
            if (b3[i] == 0) {
                flag = i;
            }
            if (flag != -1) {// 找到了
                for (; flag < sz; flag++) {// 1-从flag左往右填
                    // clang-format off
                    if(b3[flag]==0)num[flag]=1;
                    if(b3[flag]==1)num[flag]=num[flag-1]+1;
                    
                    if((b2[flag]==1&&b1[flag+1]==1)||b3[flag]==2){
                        num[flag]=num[flag-1]+1;
                      //  i+=flag; /////////////////这里可能有问题,懒得改了
                        flag = -1;// 找下一个flag      
                        break;
                    }
                }
            }
        }

        //右往左填-没问题
        for(int i = sz-1;i>=0;i--){
            if(num[i]==0){//还没填过的
                if(i==sz-1)num[i]=1;
                else num[i]=num[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<sz;i++){
            ans+=num[i];
        }
        return ans;
    }
};
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1); // 正向遍历
        vector<int> right(n, 1); // 反向遍历

        // 从左到右，满足右边比左边大的情况
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // 从右到左，满足左边比右边大的情况
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int total = 0;
        for(int i = 0; i < n; ++i) {
            total += max(left[i], right[i]);
        }

        return total;
    }
};

#include<iostream>
int main() {
    Solution2 sol;
    vector<int> ratings = {1,2,3,1,5,2,3,4,5,2,1};

    cout << "Ratings: [";
    for (int i = 0; i < ratings.size(); ++i) {
        cout << ratings[i] << (i < ratings.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    int result = sol.candy(ratings);
    cout << "Result: " << result << endl;

    return 0;
}