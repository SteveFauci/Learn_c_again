#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct mystru{
    char id[105];
    int num;
    int price;
}node;
int cmp(const void*pp1,const void*pp2){
    node*p1 = (node*)pp1;
    node*p2 = (node*)pp2;
    if(p1->price!=p2->price)return p1->price>p2->price;
    return p1->num>p2->num;
}
int my_srtcmp(const void*pp1,const void*pp2){
    node*p1 = (node*)pp1;
    node*p2 = (node*)pp2;
    return strcmp(p1->id,p2->id);
}
node nodes[105];
node ans[105];
int main(){
    int n;
    scanf("%d",&n);
    int t;
    for(int i = 0;i < n;i++){
        scanf(" %d %s %d %d",&t,nodes[i].id,&nodes[i].num,&nodes[i].price);
    }
    qsort(nodes, n,sizeof(nodes[0]),my_srtcmp);
    
    int index = 0,left = 0;
    //双指针去重

    for(int right = 0;right < n+1; right++){
        if(strcmp(nodes[left].id,nodes[right].id)==0){
            strcpy(ans[index].id,nodes[left].id);
            ans[index].num += nodes[right].num;
            ans[index].price += nodes[right].price * nodes[right].num;
        }else{
            index++;
            left = right;
            strcpy(ans[index].id,nodes[right].id);
            ans[index].num += nodes[right].num;
            ans[index].price += nodes[right].price * nodes[right].num;
        }
    }

    qsort(ans, index,sizeof(nodes[0]),cmp);
    int sum = 0;
    for(int i = 0;i < index;i++){
        sum+=ans[i].price;
        printf("%s %d %d\n",ans[i].id,ans[i].num,ans[i].price);
    }
    printf("%d\n",sum);
}

/*
6
1 A001 1 10
2 A001 2 10
3 B001 1 20
4 A001 5 10
5 B001 3 20
6 C001 1 5
*/
/*
A012 3 207
A008 5 165
A037 3 165
A051 1 165
A002 1 99
B005 14 84
A003 2 76
A020 1 56
B002 5 50
C010 1 36
A006 2 30
A005 1 26
C001 15 15
C003 1 10
*/