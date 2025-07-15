#include<stdio.h>

int isLeap(int y) {
    return(y%4==0)&&(y%100!=0)||(y%400==0);
}
int getDaysOfMonth(int y,int m) {
    int days=0;
    switch(m) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            days=31;
            break;
        case 4:case 6:case 9:case 11:
            days=30;
            break;
        case 2:
            days=isLeap(y)?29:28;
            break;
    }
    return days;
}
int main(){
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    int sum = getDaysOfMonth(y,m);
    sum -= d;
    for(int i = m+1;i<=12;i++){
        sum+=getDaysOfMonth(y, i);
    }
    printf("%d\n",sum);

    return 0;
}