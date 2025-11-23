#include<stdio.h>
int arr[10005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    char *ptr;
    int cnt = 0;
    for(int i = 0; i < 4 * n; i++){
        ptr = (char*)arr + i;
        if(*(ptr) == 0x72)cnt++;
    }
    printf("%d\n",cnt);
}