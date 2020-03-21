#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void bubblesort(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1;  j < len; j++)
        {
            if(*(arr + i) > *(arr + j))
            {
                swap((arr + i), (arr + j));
            }
        }
    }
}

void print_arr(int *arr, int len)
{
    printf("{Array : ");
    for(int i = 0; i< len; i++)
        printf("%d, ", *(arr  + i));
    printf("}\n");
}

int main(int argc, char const *argv[])
{    
    srand(time(0));
    int arr[20];
    for(int i = 0; i < 20; i++)
        arr[i] = rand() % 100;
    print_arr(arr, 20);
    bubblesort(arr, 20);
    print_arr(arr, 20);

    return 0;
}
