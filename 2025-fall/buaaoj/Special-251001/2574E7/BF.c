#include<stdio.h>
#include<string.h>
char mem[65537];
char* ptr;
char ins[1025];

void my_gets(char*s,int limit){
    fgets(s,limit,stdin);
    s[strcspn(s,"\n")] = '\0';
}
int main(){
    my_gets(ins, 1025);
    ptr = mem;
    int len = strlen(ins);
    for(int pc = 0; pc < len; pc++){
        char ch = ins[pc];
        if(ch == '<') ptr-=1;
        if(ch == '>') ptr+=1;
        if(ch == '+') *ptr+=1;
        if(ch == '-') *ptr-=1;
        if(ch == '.') putchar(*ptr);
        if(ch == ',') {
            int temp = getchar();
            *ptr = (unsigned char)temp;
        };
        if(ch == '[' && *ptr == 0) {
            int depth = 1;
            while(depth > 0 && pc + 1 < strlen(ins)){
                pc++;
                if(ins[pc] == '[') depth++;
                else if(ins[pc] == ']') depth--;
            }
        };
        if(ch == ']' && *ptr != 0) {
            int depth = 1;
            while(depth>0 && pc > 0){
                pc--;
                if(ins[pc] == ']') depth++;
                else if(ins[pc] == '[') depth--;
            }
        };
    }
}