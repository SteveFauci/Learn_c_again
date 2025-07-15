#include<stdio.h>
#include<stdlib.h>
typedef struct my_str{
    int level;
    int date;
    char head[105];
}my_new;

my_new news[105];

int cmp(const void *pp1,const void *pp2){
    my_new* p1 = (my_new*)pp1;
    my_new* p2 = (my_new*)pp2;
    if(p1->level!=p2->level)return p1->level < p2->level;
    else return p1->date < p2->date;
}
char my_switch(int a){
    switch(a){
        case 1:return 'C';
        case 2:return 'B';
        case 3:return 'A';
    }
    return 0;
}

int main(){
    int i = 0;
    char op;
    int front = 0;
    while(~scanf(" %c",&op)){
        if(op=='A'){scanf(" %d %s",&news[i].date,news[i].head);news[i].level = 3;i++;}
        if(op=='B'){scanf(" %d %s",&news[i].date,news[i].head);news[i].level = 2;i++;}
        if(op=='C'){scanf(" %d %s",&news[i].date,news[i].head);news[i].level = 1;i++;}
        if(op=='R'){
            int sz;
            qsort(news+front, i-front, sizeof(news[0]),cmp);
            scanf("%d",&sz);
            for(int j = front; j < front + sz;j++){
                char tmp = my_switch(news[j].level);
                printf("%c %d %s\n",tmp,news[j].date,news[j].head);
            }
            front+=sz;
        }
        if(op=='E'){
            qsort(news+front, i-front, sizeof(news[0]),cmp);
            for(int j = front; j < i;j++){
                char tmp = my_switch(news[j].level);
                printf("%c %d %s\n",tmp,news[j].date,news[j].head);
            }
        }
    }
}


/*
C 20240317 Analysis_of_recent_traffic_congestion_situation
A 20240317 Stock_market_crash
B 20240317 The_Future_of_Artificial_Intelligence
B 20240318 The_impact_of_climate_change_on_global_food_supply
A 20240319 Sudden_earthquake_in_the_Pacific_Plate
R 3
C 20240319 Analyze_the_causes_of_extreme_weather_conditions
R 1
A 20240319 New_York_City_Suddenly_Falls_lizard
B 20240320 Chip_Industry_Chain_Tracking
E
*/