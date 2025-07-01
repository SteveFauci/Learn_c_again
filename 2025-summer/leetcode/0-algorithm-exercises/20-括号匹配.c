#include <stdio.h>
#include <string.h>
#define MAX 10005
typedef struct {
    char str[MAX];
    int  top;
} Stack;
void init_stack(Stack* a) {
    a->top = -1;
}
void push_stack(Stack* a, char ch) {
    a->str[++a->top] = ch;
}
char top_stack(Stack* a) {
    return a->str[a->top];
}
void pop_stack(Stack* a) {
    a->top--;
}
int is_empty(Stack *a){
    return a->top==-1;
}
int is_pair(char ch, char ch2){
    if(ch == '(' && ch2 == ')'||ch == '[' && ch2 == ']'||ch == '{' && ch2 == '}')return 1;
    return 0;
}
int isValid(char* s) {
    int   sz = strlen(s);
    Stack a;
    init_stack(&a);
    for(int i = 0;i < sz; i++){
        char ch = s[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            push_stack(&a, ch);
        }else{
            if(is_empty(&a))return 0;
            char ch2 = top_stack(&a);
            pop_stack(&a);
            if(!is_pair(ch2, ch))return 0;
        }
    }
    if(!is_empty(&a))return 0;
    return 1;
}
int main(){
    char str[55];
    fgets(str,55,stdin);
    str[strcspn(str,"\n")] = '\0';
    isValid(str)?puts("true"):puts("false");
    return 0;
}