/* 7. Design and implement C/C++ Program to solve discrete Knapsack 
and continuous Knapsack problems using greedy approximation method.*/
#include<stdio.h>
#define MAX 50
int w[MAX],p[MAX],x[MAX];
double max_profite;
int i,j,n,m;
void greedyknapsack(int n,int w[],int p[],int m)
{
    double ratio[MAX];
    for(i=1;i<=n;i++)
    {
        ratio[i]=(double)p[i]/w[i];
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                double temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                int temp1=w[i];
                w[i]=w[j];
                w[j]=temp1;

                temp1=p[i];
                p[i]=p[j];
                p[j]=temp1;
            }
        }
    }
    int current_wight=0;
    max_profite=0.0;
    for(i=1;i<=n;i++)
    {
        if(current_wight+w[i]<=m)
        {
            x[i]=1;
            current_wight+=w[i];
            max_profite+=p[i];
        }
        else
        {
            x[i]=(m-current_wight)/(double)w[i];
            max_profite+=x[i]*p[i];
            break;
        }
    }
    printf("Optimal solution for greedy:%.1f\n",max_profite);
    printf("Solution vector for greedy:\n");
    for(i=1;i<=n;i++)
    printf("%d\t",x[i]);
}
int main()
{
    printf("Enter the no of object:");
    scanf("%d",&n);
    printf("Enter the object wight:");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("Enter the object profite:");
    for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
    printf("Enter the maximum capacity:");
    scanf("%d",&m);
    greedyknapsack(n,w,p,m);
    return 0;
}