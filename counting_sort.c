// counting sort : linear order sorting term  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
coutning sort.
*/

void printArray(int *arr, int len)
{
    printf("\n{Array : ");
    for(int i = 0; i < len; i++)
        printf("%d, ", arr[i]);
    printf("}\n");
}


void countingSort(int *arr, int *brr, int key, int len)
{
    int *crr = (int*)malloc(sizeof(int) * (len + 1));
    for(int i = 0; i <= key; i++)
        crr[i] = 0;
    for(int i = 0; i <= key; i++)
        crr[arr[i]] = crr[arr[i]] + 1;

    for(int i = 0; i <= key; i++)
        crr[i] = crr[i] + crr[i - 1];

    for(int i = len - 1; i >= 0; i--)
    {
        brr[crr[arr[i]]] = arr[i];
        crr[arr[i]] -= 1;
    }
}


int maxKey(int *arr, int len)
{
    int max = arr[0];
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{

    int arr[8] = {2,5,3,0,2,3,0,3};
    int brr[8];
    int max = maxKey(arr, 8);
    countingSort(arr, brr, max, 8);
    printArray(arr, 8);
    printArray(brr, 8);

    return 0;
}
