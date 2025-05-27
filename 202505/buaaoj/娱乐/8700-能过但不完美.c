#include <stdio.h>
#include <math.h>
int main(){
    int T,cnt;
    unsigned u;
    scanf("%d",&T);
    while(T--){
        scanf("%u",&u);
        u++;
        int a =__builtin_popcount(u);
        if(a==0||a==1)puts("Yes");
        else puts("N0");
    }
}