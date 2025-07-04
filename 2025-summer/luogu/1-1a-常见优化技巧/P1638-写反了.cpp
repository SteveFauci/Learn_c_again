//题目要返回第一个最短区间，我这返回最后一个区间了。。
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> p(n);
    for(int i = 0;i< n;i++){
        scanf("%d",&p[i]);
    }
    unordered_map<int, int> my_map;
    
    int left = 0,len = n;
    int l,r;
    for(int right = 0; right < n;right++){
        my_map[p[right]]++;
        while(my_map.size()==m){
            my_map[p[left]]--;
            if(my_map[p[left]]==0)my_map.erase(p[left]);
            left++;
            if(my_map.size()==m){
                len = min(len,right-left + 1);
                l = left;
                r = right;
            }
        };
    }
    printf("%d %d\n",l,r);
    return 0;
}
// 12 5
// 2 5 3 1 3 2 4 1 1 5 4 3