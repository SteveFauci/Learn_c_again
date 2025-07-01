#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-6
typedef struct {
    char  name[55];
    int   id;
    double score;
    struct {
        int h;
        int m;
        int s;
        int sum;
    } t;
} my_struct;
int cmp(const void* pp1, const void* pp2) {
    my_struct*p1 = (my_struct*)pp1;
    my_struct*p2 = (my_struct*)pp2;
    if(p1->score - p2->score > eps) return -1;
    else if(p1->score - p2->score < -eps) return 1;
    else if(fabs(p1->score - p2->score) < eps){
        if(p1->t.sum > p2->t.sum)return 1;
        else if(p1->t.sum < p2->t.sum)return -1;
        else return p1->id > p2->id;
    }
    return 0;
}
int main(){
    my_struct stu[1005];
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n; i++){
        scanf("%s%d%lf%d:%d:%d",stu[i].name,&stu[i].id,&stu[i].score,&stu[i].t.h,&stu[i].t.m,&stu[i].t.s);
        stu[i].t.sum = stu[i].t.h * 3600 + stu[i].t.m * 60 + stu[i].t.s;
    }
    qsort(stu,n,sizeof(stu[0]),cmp);
    for(int i = 0;i < n; i++){
        printf("%s %d %.2lf %02d:%02d:%02d\n",stu[i].name,stu[i].id,stu[i].score,stu[i].t.h,stu[i].t.m,stu[i].t.s);
    }
    return 0;
}