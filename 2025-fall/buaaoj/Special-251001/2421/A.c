#include<stdio.h>

int main(){
    int t;
    long long a,b,k;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&k);
        long long B = 1;
        int flag = 0;
        for(int i = 0; i < k; i++){
            B *= b;
            if(B > a){
                flag = 1;
                break;
            }
        }
        if(flag){
            puts("n^k");
        }else if(B == a){
            puts("n^k\\log n");
        }else{
            puts("n^{\\log_ba}");
        }
    }
    return 0;
}