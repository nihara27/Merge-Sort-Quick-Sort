
#include <stdio.h>
struct Package
{
    int id;
    int weight;
};

void swap(struct Package *a, struct Package *b)
{
    struct Package temp = *a;
    *a = *b;
    *b = temp;
}
int partition(struct Package arr[], int low, int high)
{
    int pivot = arr[high].weight;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].weight <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(struct Package arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(packages, 0, n - 1);

    printf("\nPackages after Quick Sort:\n");
    display(packages, n);

    return 0;
}
