#include<stdio.h>

int arr[30005];
int MOD = 10007;

int main(){
    int n;
    scanf("%d",&n);
    int x,m;
    while(n--){
        scanf("%d%d",&x,&m);
        int ans = 0;
        for(int i = 0;i < m; i++){
            scanf("%d",&arr[i]);
        }
        for(int i = m - 1; i>=0;i--){
            ans = (((ans%MOD) * (x%MOD))%MOD + (arr[i])%MOD)%MOD;
        }
        printf("%d\n",ans);
    }
}