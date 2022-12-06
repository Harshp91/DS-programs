#include <stdio.h>
 
void sorted_sets(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
 
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n, m;
    printf("Enter Size of 1st and 2nd Array: ");
    scanf("%d %d", &n, &m);
    int a[100], b[100];
    printf("Enter Elements of 1st Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Elements of 2nd Array: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
 
    sorted_sets(a, m);
    sorted_sets(b, n);
    int i = 0,j = 0,k = 0;
    int c[40];
 
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else if (a[i] > b[j])
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    printf("Array after union\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
 return 0;
}

