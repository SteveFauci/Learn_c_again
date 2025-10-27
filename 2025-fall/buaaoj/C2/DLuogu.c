#include<stdio.h>
#include<string.h>
char str1[2005];
char str2[2005];
void my_gets(char*s,int limit){
    fgets(s,limit,stdin);
    s[strcspn(s,"\n")] = '\0';
}
int num1[2005];
int num2[2005];
int ans[4010];
int my_clear[2005];
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        memset(ans,0,sizeof(ans));

        my_gets(str1, 2005);
        my_gets(str2, 2005);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        for(int i = 1; i <= len1; i++) num1[i] = str1[len1 - i] - '0';
        for(int i = 1; i <= len2; i++) num2[i] = str2[len2 - i] - '0';
        for(int i = 1; i <= len2; i++){
            for(int j = 1; j <= len1; j++){
                ans[i+j-1] += num1[j] * num2[i];
            }
        }
        for(int i  = 1; i <= len1+len2; i++){
            if(ans[i] > 9){
                ans[i+1]+=ans[i] / 10;
                ans[i]%=10;
            }
        }
        int ans_len = len1 + len2;
        while(!ans[ans_len] && ans_len > 1)ans_len--;
        for(int i = ans_len; i >= 1; i--){
            printf("%d",ans[i]);
        }
        puts("");
    }
}