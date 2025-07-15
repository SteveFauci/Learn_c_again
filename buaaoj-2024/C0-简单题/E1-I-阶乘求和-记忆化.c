//记忆化防超时
#include<stdio.h>
int arr[100005];
void init(){
    arr[1] = arr[0] = 1;
    for(int i = 2;i <= 100005;i++){
        arr[i]=i*arr[i-1];
        arr[i]%=10007;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    init();
    while(t--){
        int n;
        scanf("%d",&n);
        int sum = 0;
        for(int i = 0; i <= n;i++){
            sum+=arr[i];
            sum%=10007;
        }
        printf("%d\n",sum);
    }
}