#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int a[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (a[j] > a[j+1])
              swap(&a[j], &a[j+1]);
}
void print(int a[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[] = {64,5,626,3,488,56};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    printf("Sorted array: \n");
    print(a, n);
    return 0;
}
