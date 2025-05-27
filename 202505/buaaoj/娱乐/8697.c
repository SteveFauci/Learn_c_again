#include<stdio.h>
int a[10]={6,2,5,5,4,5,6,3,7,6};
int stick(int i)
{
    int rs=0,k;
    if(!i)rs=6;
    while(i)
    {
        k=i%10;
        rs+=a[k];
        i/=10;
    }
    return rs;
}
int main()
{

    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        n-=4;
        int cnt=0;
        for(i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                if(stick(i)+stick(j)+stick(i+j)==n) 
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
//加上了第6行 ==0
//23 25行改成了=0
