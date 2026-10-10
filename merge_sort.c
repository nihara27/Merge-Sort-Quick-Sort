
#include <stdio.h>
struct Package
{
    int id;
    int weight;
};
void merge(struct Package arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    struct Package temp[right - left + 1];
    while (i <= mid && j <= right)
    {
        if (arr[i].weight <= arr[j].weight)
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(struct Package arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(struct Package arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("P%d(%d) ", arr[i].id, arr[i].weight);
    }
    printf("\n");
}
int main()
{
    struct Package packages[] =
    {
        {1, 20},
        {2, 15},
        {3, 20},
        {4, 10},
        {5, 15},
        {6, 20},
        {7, 25},
        {8, 10}
    };
    int n = 8;
    printf("Original packages:\n");
    display(packages, n);
    mergeSort(packages, 0, n - 1);
    printf("\nPackages after Merge Sort:\n");
    display(packages, n);
    return 0;
}
