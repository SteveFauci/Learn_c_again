#include<string.h>
#include<stdio.h>
#include<ctype.h>

void my_gets(char*s,int limit){
    fgets(s,limit,stdin);
    s[strcspn(s,"\n")] = '\0';
}

char c[1005];

int main(){
    int L;
    scanf("%d",&L);
    getchar();
    my_gets(c, 1005);
    int sz = strlen(c);
    
    for(int i = 0; i < sz; i++){
        int k = L - (i % L);
        
        if(isupper(c[i])){
            int temp = c[i] - 'A';
            temp = (temp - k) % 26;
            if(temp < 0) temp += 26;
            c[i] = 'A' + temp;
        }
        else if(islower(c[i])){
            int temp = c[i] - 'a';
            temp = (temp - k) % 26;
            if(temp < 0) temp += 26;
            c[i] = 'a' + temp;
        }
        else if(isdigit(c[i])){
            int temp = c[i] - '0';
            temp = (temp - k) % 10;
            if(temp < 0) temp += 10;
            c[i] = '0' + temp;
        }
        else if(c[i] == '*'){
            c[i] = ' ';
        }
    }
    puts(c);
}