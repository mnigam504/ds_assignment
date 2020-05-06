#include<stdio.h>
void isort(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 &&  a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return;
}
int main()
{
    int i,a[]={3,5,13,2,64,9};
    int n= sizeof(a)/sizeof(int);
    isort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 1;
}
