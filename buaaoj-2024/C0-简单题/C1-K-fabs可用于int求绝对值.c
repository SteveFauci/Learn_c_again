#include<stdio.h>
#include<math.h>
int arr[1000005];
int main(){
    int T,n,a;
    scanf("%d",&T);
    while(T--){
        long long sum = 0;
        scanf("%d",&n);
        int index = (n+1)/2;
        for(int i = 1; i <= n; i++){
            scanf("%d",&arr[i]);
        }
        for(int i = 1; i <= n;i++){
            sum+=fabs(arr[i]-arr[index]);
        }
        printf("%lld\n",sum);
    }
}