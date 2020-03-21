# selectionsor.py 

import array 
import random 


def min_index(arr, from_, to):
    min = from_
    for i in range(from_ + 1, to + 1):
        if arr[min] > arr[i]:
            min = i 
    return min 


def selectionsort(arr, from_, to):
    for i in range(from_, to):
        min = min_index(arr, i, to)
        if min != i:
            temp = arr[min]
            arr[min] = arr[i]
            arr[i] = temp 


if __name__ == '__main__':
    lst = []
    for i in range(0, 20):
        lst.append(random.randint(1, 100))
    arr = array.array('i', lst)
    print(arr)
    selectionsort(arr, 0, 19)
    print(arr)
