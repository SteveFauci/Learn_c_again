#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define lll int
#define ll long long
int main(){
    lll a[300];
    ll n;
    ll ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            for(int k=i;k<=j;++k){
                ans+=a[k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
//10行没初始化ans
//17行加上了=