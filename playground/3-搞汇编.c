#include<stdio.h>
int sum(int num1, int num2) {
    int ret = 0;
    __asm__ volatile(
        "addl %%edx, %%eax"  
        : "=a"(ret)          
        : "a"(num1), "d"(num2) 
        :
    );
    return ret;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",sum(a,b));
    return 0;
}