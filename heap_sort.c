// Heap sort 

#include <stdio.h>
#include <stdlib.h>

struct Heap 
{
    int *arr; 
    int capacity;
    int size;
};

struct Heap* create_heap(int len)
{
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->capacity = len;
    heap->arr = (int*)malloc(sizeof(int) * heap->capacity);
    heap->size = -1;
    return heap;
}


int parent(struct Heap *hp, int child)
{
    if(child <= 0 || child > hp->size)
    {
        return -1;
    }
    return (child-1)/2;
}

int left_child(struct Heap *hp, int parent_)
{
    if(parent_ < 0 || parent_ > hp->size)
    {
        return -1;
    }
    
    int lc = 2 * parent_ + 1; 
    if(lc > hp->size)
        return -1;
    return lc;
}

int right_child(struct Heap *hp, int parent_)
{
    if(parent_ < 0 || parent_ > hp->size)
        return -1; 
    int rc = 2 * parent_ + 2; 
    if(rc > hp->size)
        return -1; 
    return rc;
}

void insert_key(struct Heap* hp, int key)
{
    hp->size++;
    int dummy = hp->size;
    while(dummy > 0 && hp->arr[(dummy - 1)/2] < key)
    {
        hp->arr[dummy] = hp->arr[(dummy - 1) / 2];
        dummy = (dummy - 1)/2;
    } 
    hp->arr[dummy] = key;
}

void percolate_down(struct Heap *hp, int index)
{
    int lc = left_child(hp, index);
    int rc = right_child(hp, index);
    int max;
    int temp = 0;
    if(lc != -1 && hp->arr[index] <  hp->arr[lc])
    {
        max = lc; 
    }
    else 
    {
        max = index; 
    }
    if(rc != -1 && hp->arr[max] < hp->arr[rc])
    {
        max = rc;
    }
    if(max != index)
    {
        temp =  hp->arr[index];
        hp->arr[index] = hp->arr[max];
        hp->arr[max] = temp;
        percolate_down(hp, max);
    }
}

int deletekey(struct Heap *hp)
{
    int temp;
    int data;
    temp = hp->arr[0];
    data = temp;
    hp->arr[0]= hp->arr[hp->size];
    hp->arr[hp->size] = temp; 
    hp->size--;
    percolate_down(hp, 0);
    return data;
}

void print_heap(struct Heap *hp)
{
    printf("{Heap : ");
    for(int i = 0; i <= hp->size; i++)
    {
        printf("%d, ", hp->arr[i]);
    }
    printf("}\n");
}


void heap_sort(struct Heap *hp)
{
    int dummy = hp->size; 
    int temp;
    for(int i = 0; i < dummy; i++)
    {
        temp = hp->arr[hp->size];
        hp->arr[hp->size] = hp->arr[0];
        hp->arr[0] = temp; 
        hp->size--;
        percolate_down(hp, 0);
    }

    printf("{Sorted Heap : ");
    for(int i = 0; i <= dummy; i++)
    {
        printf("%d, ", hp->arr[i]);
    }
    printf("}\n");
}

int main(int argc, char const *argv[])
{
    struct Heap *hp = create_heap(10);
    insert_key(hp, 21);
    insert_key(hp, 11);
    insert_key(hp, 18);
    insert_key(hp, 1);
    insert_key(hp, 31);
    heap_sort(hp);
    return 0;
}
