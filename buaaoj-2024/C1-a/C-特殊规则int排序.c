#include<stdio.h>
#include<stdlib.h>
int pop_count(int num){
    int sum = 0;
    for(int i = 0; i < 32; i++){
        sum += (num >> i) & 1; 
    }
    return sum;
}
int cmp(const void*pp1,const void*pp2){
    int*p1 = (int*)pp1;
    int*p2 = (int*)pp2;
    int cnt1 = pop_count(*p1);
    int cnt2 = pop_count(*p2);
    if(cnt1!=cnt2)return cnt1 > cnt2;
    else return *p1 < *p2;
}
int arr[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    for(int i = 0; i < n; i++){
        printf("%d %d\n",arr[i],pop_count(arr[i]));
    }
    return 0;
}