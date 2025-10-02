#include <algorithm>
#include<cstdio>
#include <vector>
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    while(q--){
        int key;
        scanf("%d",&key);
        printf("%d %d\n",(int)(std::upper_bound(arr.begin(),arr.end(),key) - arr.begin()),(int)(std::lower_bound(arr.begin(),arr.end(),key)-arr.begin()));
    }
}