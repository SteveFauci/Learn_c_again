// 军训小游戏报数：前N个能被k整除的数或数位含有k的数。
#include <stdio.h>
int is_valid(int num,int k){
    if(!k){
        if(num%10==0)return 1;
        else if(num>=100&&(num/10)%10==0)return 1;
        else if(num>=1000&&(num/100)%10==0)return 1;
        else if(num>=10000&&(num/1000)%10==0)return 1;
    }else{
        if(!(num%k))return 1;
        if(num%10 == k)return 1;
        if((num%100)/10 == k)return 1;
        if((num%1000)/100 == k)return 1;
        if((num%10000)/1000 == k)return 1;
    }
    return 0;
}

int main() {
    int N,x;
    int num = 0;
    scanf("%d%d",&N,&x);
    int cnt = 0;
    while(cnt<N){
        num++;
        if(is_valid(num, x)){
            printf("%d ",num);
        cnt++;}
    }
    return 0;
}