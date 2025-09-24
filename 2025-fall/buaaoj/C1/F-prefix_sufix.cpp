#include <cstdio>
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int arr[100005];
int pre[100005];
int suf[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    pre[0] = arr[0];
    suf[n-1] = arr[n-1];

    for(int i = 1; i < n; i++){
        pre[i] = gcd(pre[i-1],arr[i]);
    }
    for(int i = n-2; i >= 0; i--){
        suf[i] = gcd(suf[i+1],arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", suf[1]);
        } else if (i == n-1) {
            printf("%d", pre[n-2]);
        } else {
            printf("%d", gcd(pre[i-1], suf[i+1]));
        }
        if (i < n-1) printf(" ");
        else printf("\n");
    }

}