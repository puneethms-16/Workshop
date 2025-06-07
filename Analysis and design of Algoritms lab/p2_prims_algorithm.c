/* 2. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given 
connected undirected graph using Prim’s algorithm.*/
#include<stdio.h>
#define INF 999
int prims(int c[10][10],int n,int s)
{
    int i,j,u,ver[10],v[10],d[10],min,sum=0;
    for(i=1;i<=n;i++)
    {
        ver[i]=s;
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1;i<=n-1;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        if(v[j]==0&&d[j]<min)
        {
            min=d[j];
            u=j;
        }
        v[u]=1;
        sum=sum+d[u];
        printf("\n%d->%d sum=%d",ver[u],u,sum);
        for(j=1;j<=n;j++)
        if(v[j]==0&&c[u][j]<d[j])
        {
            d[j]=c[u][j];
            ver[j]=u;
        }
    }
    return sum;
}
int main()
{
    int n,c[10][10],i,j,res,s;
    printf("enter the N value:");
    scanf("%d",&n);
    printf("Enter the graph data:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("Enter the source node:");
    scanf("%d",&s);
    res=prims(c,n,s);
    printf("\nthe cost=%d",res);
    return 0;
}