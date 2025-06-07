/* 1. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given
connected undirected graph using Kruskal's algorithm. */
#include<stdio.h>
#define MAX 100
#define INF 999
int p[MAX],c[MAX][MAX],t[MAX][3];
int find(int v)
{
    while(p[v])
    v=p[v];
    return v;
}
void union1(int i,int j)
{
    p[j]=i;
}
void kruskal(int n)
{
    int i,j,k,u,v,res1,res2,min,sum=0;
    for(k=1;k<n;k++)
    {
        min=INF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)continue;
                if(c[i][j]<min)
                {
                    u=find(i);
                    v=find(j);
                if(u!=v)
                {
                    res1=i;
                    res2=j;
                    min=c[i][j];
                }
                }
            }
        }
        union1(res1,find(res2));
        t[k][1]=res1;
        t[k][2]=res2;
        sum=sum+min;
        c[res1][res2]=c[res2][res1]=INF;
    }
    printf("Cost of the spaning tree is:%d\n",sum);
    printf("Edge of the spaning tree is:\n");
    for(i=1;i<n;i++)
    printf("%d->%d\n",t[i][1],t[i][2]);
}
int main()
{
    int i,j,n;
    printf("Enter the N value:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    p[i]=0;
    printf("Entre the Graph data:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    kruskal(n);
    return 0;
}