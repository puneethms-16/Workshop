/* 5. Design and implement C/C++ Program to obtain the Topological ordering 
of vertices in a given digraph.*/
#include<stdio.h>
int temp[10],k=0;
void sort(int a[10][10],int id[10],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(id[i]==0)
        {
            id[i]=-1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1&&id[j]!=-1)
                id[j]--;
            }
            i=0;
        }
    }
}
int main()
{
    int a[10][10],id[10],n,i,j;
    printf("Enter the N value:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        id[i]=0;
    }
    printf("Enter the graph data:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]==1)
        id[j]++;
    }
    sort(a,id,n);
    if(k!=n)
    printf("the topological ordering is not possible");
    else
    {
        printf("the topological order is=");
        for(i=1;i<=n;i++)
        printf("%d ",temp[i]);
    }

}