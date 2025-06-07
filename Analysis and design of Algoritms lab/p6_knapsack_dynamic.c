/* 6. Design and implement C/C++ Program to solve 0/1 Knapsack problem
using Dynamic Programming method.*/
#include<stdio.h>
int w[10],p[10],n;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knap(int i,int m)
{
    if(i==n)
    return w[i]>m?0:p[i];
    if(w[i]>m)
    return knap(i+1,m);
    return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}
int main()
{
    int i,m,max_profite;
    printf("Enter the no of object:");
    scanf("%d",&n);
    printf("Enter the knapscak capacitye:");
    scanf("%d",&m);
    printf("Enter the profite followed by wiget:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i],&w[i]);
    }
    max_profite=knap(1,m);
    printf("Max profite:%d",max_profite);
    return 0;
}