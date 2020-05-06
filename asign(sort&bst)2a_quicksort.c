#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int hoare_partition(int a[],int l,int h)
{
    int pivot= a[l];
    int i=l-1,j=h+1;
    for(;;)
    {
        do{
            i++;
        }while(a[i]<pivot);

        do{
            j--;
        }while(a[j]>pivot);

        if(i>=j)
            return j;

        swap(&a[i],&a[j]);
    }
}
void q_sort(int a[],int l,int h)
{
    begin:
    if(l<h)
    {
        int p=hoare_partition(a,l,h);
        q_sort(a,l,p);
        l=p+1;
        goto begin;
    }
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[]={3,46,8,39,34,84};
    int n=sizeof(a)/sizeof(a[0]);
    q_sort(a,0,n-1);
    printf("Sorted array is: ");
    print(a,n);
    return 0;
}
