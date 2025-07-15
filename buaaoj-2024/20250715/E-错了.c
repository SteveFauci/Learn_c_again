// 这题是考递归，但是我写了个栈在这，到最后差一秒没交，估计也是错的
#include<stdio.h>
#include<string.h>
void my_gets(char*s,int limit){
    fgets(s,limit,stdin);
    s[strcspn(s,"\n")] = '\0';
}
char str[1000005];
int top = -1;
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        int flag = 0;
        int top = -1;
        my_gets(str, 1000005);
        int sz = strlen(str);
        for(int i = 0; i < sz; i++){
            if(str[i]=='a')top++;
            if(str[i]=='b')top--;
            if(top<-1){puts("Dead Alex");flag = 1;break;}
        }
        if(!flag){
        if(top==-1)puts("Happy Alex");
        if(top>-1)puts("Sad Alex");}
    }

    return 0;
}