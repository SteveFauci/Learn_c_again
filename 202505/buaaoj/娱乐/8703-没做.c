#include<stdio.h>
#include<string.h>
int main()
{
    int n,cnt=0,flag=0;
    double t[110],sum[110];
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%lf",&t[i]);
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=5;i++)
            sum[4]+=t[i];
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]-t[i-4]+t[i];
            if(sum[i]<50.0)
                cnt++;
            if(cnt>=5)
            {
                flag=1;
                for(int j=i-9;j<=i;j++)
                    if(t[j]<10.0)
                        printf("Success %d\n",j);
                break;
            }
        }
        if(flag)
            printf("Failure\n");
    }
    return 0;
}