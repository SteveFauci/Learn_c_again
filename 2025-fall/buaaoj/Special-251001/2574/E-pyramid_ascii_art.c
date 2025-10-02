#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    n*=2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            putchar(' ');
        }
        if(!(i % 2)){
            for(int j = 0; j < (n-i)/2; j++){
                printf("\\--/");
            }
        }else{
            for(int j = 0; j < 1+ (n-i)/2; j++){
                printf("\\/");
                if(j != (n-i)/2){
                    printf("  ");
                }
            }
        }
        puts("");
    }
}