#include<stdio.h>
int arr[25];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i<n;i++){
        printf("%d ",arr[n-1-i]);
    }
    puts("");
    int m;
    scanf("%d",&m);
    printf("%d\n",arr[n-m]);
    return 0;
}