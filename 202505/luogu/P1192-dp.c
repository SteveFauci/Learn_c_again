#include<stdio.h>
int n,k,arr[100005];
int main(){
    scanf("%d%d",&n,&k);
    arr[0] = arr[1] =1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j>=0){
                arr[i] += arr[i-j]%100003;
            }
        }
    }
    printf("%d\n",arr[n]%100003);
    return 0;
}