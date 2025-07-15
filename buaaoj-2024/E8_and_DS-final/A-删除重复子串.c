//双指针，一遍过。
#include<stdio.h>
#include<string.h>

char str[1005];
int main(){
    while(fgets(str, 1005, stdin)!=NULL){
        str[strcspn(str, "\n")] = '\0';
        int sz = strlen(str);
        int ptr = sz/2;
        int flag = 0;
        for(int i = 0; i < sz/2;i++){
            if(str[i]!=str[ptr+i])flag=1;
        }
        if(flag)puts(str);
        else puts(str+ptr);
    }
}