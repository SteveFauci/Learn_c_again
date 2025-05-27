#include<stdio.h>
int arr[100005]={0,1};

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 2;i <= k; i++){
        arr[i]=(2*arr[i-1])%100003;
    }
    int sum = 0;
    for(int i = k+1 ;i <= n; i++){
        for(int j = i-k; j <= i; j++){
            sum += arr[j]%100003;
            sum%=100003;
        }
        arr[i] = sum;
        sum = 0;
    }
    printf("%d\n",arr[n]);
}