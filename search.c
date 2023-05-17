#include <stdio.h>
#include <stdlib.h>
void linearSearch(int arr[], int val, int n)
{
    int i, flag = 0, index;
    for (int i = 0; i < n; i++)
    {
        if (val == arr[i])
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 1)
        printf("\nElement is found at index %d", index);
    else
        printf("\nElement not found");
}
int sort(int arr[], int n)
{
    int i, temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nThe sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void binarySearch(int arr[], int val, int n)
{
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == val)
        {
            printf("\nElement is found at index %d", mid);
            break;
        }
        else if (arr[mid] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low > high)
        printf("\n %d does not exist in the array", val);
}
int main()
{
    int option, val, arr[100], n;
    printf("\nEnter the number of elements in the array:");
    scanf("%d", &n);
    printf("\nEnter the  elements in the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\n1.Linear Search\n2.Binary Search\n3.Exit");
        printf("\nEnter your option :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the value you want search:");
            scanf("%d", &val);
            linearSearch(arr, val, n);
            break;
        case 2:
            sort(arr, n);
            printf("\nEnter the value you want search:");
            scanf("%d", &val);
            binarySearch(arr, val, n);

            break;
        }
    } while (option != 3);
    return 0;
}
