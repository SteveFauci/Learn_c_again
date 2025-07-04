// i有意义的时候还是不要从0开始比较好（？
#include <stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int arr[610];
int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++){
        int temp;
        scanf("%d",&temp);
        arr[temp]++;
        int sum = 0;
        for(int j = 600; j >= 0; j--){
            sum += arr[j];
            if(sum>=max(1,w*i/100)){
                printf("%d ",j);
                break;
            }
        }
    }
}