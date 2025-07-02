#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*pp1,const void *pp2){
    char*p1 = (char*)pp1;
    char*p2 = (char*)pp2;
    if(strlen(p1)!=strlen(p2))return strlen(p1) < strlen(p2);
    else return strcmp(p1,p2);
}
char strs[100005][105];
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        fgets(strs[i],105,stdin);
        strs[i][strcspn(strs[i],"\n")] = '\0';
    }
    qsort(strs, n, sizeof(strs[0]),cmp);
    for(int i = 0; i < n; i++){
        puts(strs[i]);
    }
    return 0;
}
//别的没啥好说的，连题目上都说：要记得使用 getchar 吃掉第一行末的换行符。