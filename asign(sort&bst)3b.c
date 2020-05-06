#include<stdio.h>
#include<string.h>
void merge(char a[],int l,int m,int r)
{
    int n1=m-l+1, n2=r-m,i,j;
    //printf("n1=%d n2=%d\n",n1,n2);
    char left[n1];
    char right[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=a[m+1+j];
    }
    //printf("left string is:%s\n",left);
    //printf("right string is:%s\n",right);
    i=0;j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=left[i++];
    }
    while(j<n2)
    {
        a[k++]=right[j++];
    }

}
void mergesort(char a[],int l,int r)
{
    if(r>l)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int i;
    char a[]="Test case";
    int n=strlen(a);
    //printf("%s\n",a);
    //printf("%d\n",n);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}

