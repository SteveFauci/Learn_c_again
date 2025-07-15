#include<string.h>
#include<stdio.h>
typedef struct my_struct{
    char name[35];
    int h1,m1,h2,m2;
}train;

train trains[35];
char str1[35],str2[35];

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m;i++){
        scanf("%s %d:%d %d:%d",trains[i].name,&trains[i].h1,&trains[i].m1,&trains[i].h2,&trains[i].m2);
    }
    while(n--){

        scanf(" %s %s",str1,str2);
        int h1,m1,h2,m2;
        int flag1 = 0,flag2 = 0;
        for(int i = 0; i < m; i++){
            if(strcmp(str1,trains[i].name)==0){h1=trains[i].h2;m1=trains[i].m2;flag1 = 1;}
            if(strcmp(str2,trains[i].name)==0){h2=trains[i].h1;m2=trains[i].m1;flag2 = 1;}
        }
        if(!(flag1 && flag2))puts("No Data");
        else {
            int h = h2 - h1;
            int m = m2 - m1;
            if(m<0){h--;m+=60;}
            if(h<0 || m<=0){puts("No Data");continue;}
            printf("%02d:%02d %02d:%02d %02d:%02d\n",h1,m1,h2,m2,h,m);
        }
    }
}