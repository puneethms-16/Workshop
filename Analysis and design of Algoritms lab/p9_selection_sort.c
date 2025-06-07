/* 9. Design and implement C/C++ Program to sort a given set of n integer elements using 
Selection Sort method and compute its time complexity. Run the program for varied values 
of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. 
The elements can be read from a file or can be generated using the random number generator.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int arr[],int n)
{
    int i,j,min_index;
    for(i=1;i<=n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<=n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}
void generaterandomnumber(int arr[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        arr[i]=rand()%10000;
    }
}
int main()
{
    int n;
    printf("Enter the no of elementa:");
    scanf("%d",&n);
    if(n<=5000)
    {
        printf("Plase enter the grater than 5000");
        return 0;
    }
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocatiion is failed");
        return 1;
    }
    generaterandomnumber(arr,n);
    clock_t start=clock();
    selectionsort(arr,n);
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements:%f seconds\n",n,time_taken);
    return 0;
}