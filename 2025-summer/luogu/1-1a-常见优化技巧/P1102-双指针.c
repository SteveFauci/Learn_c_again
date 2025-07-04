#include<stdio.h>
#include<stdlib.h>
int arr[200005];
int cmp(const void*pp1,const void*pp2){
    return *(int*)pp1 > *(int*)pp2;
}
int main(){
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i = 0;i < n;++i){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    long long cnt = 0;
    int left = 0,right = 0;
    for(int i = 0;i < n;i++){
        while(left<n && arr[left] < arr[i] - c){
            left++;
        }
        while(right<n && arr[right] <= arr[i] - c){
            right++;
        }
        if(arr[i] - arr[left] == c)cnt += right-left;
    }
    printf("%lld\n",cnt);
}