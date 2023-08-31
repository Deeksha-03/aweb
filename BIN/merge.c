/*Sort a given set of N integer elements using Merge Sort technique and
compute its time taken. Run the program for different values of N and record
the time taken to sort.*/
#include<stdio.h>
//int array[20];
//int n;
int array[20],n,m,a2[20];
int c[40];

void merge()
{
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(array[i]<a2[j])
        {
            c[k]=array[i];
            i++;
            k++;
        }
        else
        {
            c[k]=a2[j];
            j++;
            k++;
        }
    }
    while(i< n)
    {
        c[k]=array[i];
        i++;
        k++;
    }
    while(j< m)
    {
        c[k]=a2[j];
        j++;
        k++;
    }
    for (i = 0; i < n+m; i++)
    {
        array[i]=c[i];
    }
}

void main()
{
    int i;

    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the number of elements\n");
    scanf("%d",&m);
    printf("Enter the elements of the array\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a2[i]);
    }
    merge();
    printf("Sorted array:\n");
    for (i = 0; i < n+m; i++)
    {
       // array[i]=c[i];
        printf("%d ", array[i]);
    }
}

