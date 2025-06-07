/* 10. Design and implement C/C++ Program to sort a given set of n integer elements using 
Quick Sort method and compute its time complexity. Run the program for varied values of 
n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. 
The elements can be read from a file or can be generated using the random number generator.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i,j;
    i=(low-1);
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void generaterandomnumber(int arr[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        arr[i]=rand()%100000;
    }
}
int main()
{
    int n;
    printf("Enter the no of element:");
    scanf("%d",&n);
    if(n<=5000)
    {
        printf("Please eanter the grater than 5000");
        return 1;
    }
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("memory allocation is failed");
        return 1;
    }
    generaterandomnumber(arr,n);
    clock_t start=clock();
    quicksort(arr,0,n-1);
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d element %f seconds",n,time_taken);
    return 0;
}