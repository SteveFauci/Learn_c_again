// #include<stdio.h>
// int main(){
//     int x,y;
//     scanf("%d%d",&x,&y);
//     printf("%d\n",x+y);
//     fscanf(stdin,"%d%d",&x,&y);//第一个参数是stdin
//     fprintf(stdout,"%d\n",x+y);//第一个stdout
//     return 0;
// }
#include <stdio.h>
int main() {
    char ch;
    if (freopen("out.txt", "w", stdout) == NULL) {
        perror("Error!!");
        return -1;
    }
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    return 0;
}