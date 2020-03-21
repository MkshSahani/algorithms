#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int from, int to)
{
    int temp = 0;
    int x = arr[to];
    int i = from - 1;
    for(int j = from; j < to; j++)
    {
        if(arr[j] <= x)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[to];
    arr[to] = temp;

    return i + 1;
}

void quicksort(int *arr, int from, int to)
{
    if(from < to)
    {
    int q = partition(arr, from, to);
    quicksort(arr, from, q - 1);
    quicksort(arr, q + 1, to);
    }
}

void print_arr(int *arr, int len)
{
    printf("\n{Array : ");
    for(int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
    printf("}\n");
}

int main()
{
    srand(time(0));
    int arr[20];
    for(int i = 0; i < 20; i++)
        arr[i] = rand() % 100;
    print_arr(arr, 20);
    quicksort(arr, 0, 19);
    print_arr(arr, 20);

    return 0;
}
