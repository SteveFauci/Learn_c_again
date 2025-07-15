#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i = n - 1; i >0 ;i--){
        int sum = i,cnt = i+1;
        while(sum<n){
            sum+=cnt,cnt++;
        }
        if(sum==n){
            printf("%d=%d",n,i);
            int sum2 = i;
            int cnt = i+1;
            while(sum2<n) {
                printf("+%d",cnt);
                sum2+=cnt;
                cnt++;
            }
            return 0;
        }
    }
}