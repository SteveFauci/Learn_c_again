//栈的本质维护一个数组维护一个指针就好了。
//这样可以不用stl库纯手搓，也能避免做题之前手搓一大堆仿stl函数。
#include <stdio.h>
#include <string.h>
int pair(char ch, char ch2) {
    if ((ch == '(' && ch2 == ')') || (ch == '[' && ch2 == ']') || (ch == '{' && ch2 == '}'))return 1;
    return 0;
}
int isValid(char* s) {
    int  sz = strlen(s);
    char Stack[10005] = {'\0'};
    int  top = -1;
    for (int i = 0; i < sz; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            top++;
            Stack[top] = ch;
        } else {
            if (top >= 0) {
                char ch2 = Stack[top];
                top--;
                if(!pair(ch2,ch))return 0;
            }else return 0;
        }
    }
    if(top!=-1)return 0;
    return 1;
}
int main(){
    char str[55];
    fgets(str,55,stdin);
    str[strcspn(str,"\n")] = '\0';
    isValid(str)?puts("true"):puts("false");
    return 0;
}
