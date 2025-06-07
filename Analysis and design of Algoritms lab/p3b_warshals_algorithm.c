/* 3B. Design and implement C/C++ Program to find the transitive closure 
using Warshal’s algorithm.*/
#include<stdio.h>
void warshal(int p[][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    p[i][j]=p[i][j]||p[i][k]&&p[k][j];
}
int main()
{
    int a[10][10],n,i,j;
    printf("Enter the N value:");
    scanf("%d",&n);
    printf("Enter the garpha data:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshal(a,n);
    printf("resultent path matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}