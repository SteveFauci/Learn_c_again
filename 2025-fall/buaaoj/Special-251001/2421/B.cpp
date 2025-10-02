#include<stdio.h>
int arr[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int temp = 0;
        scanf("%d",&temp);
        arr[temp]++;
        if(arr[temp] > n / 2){
            printf("%d\n",temp);
            break;
        }
    }
    return 0;
}