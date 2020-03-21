# quicksort.py 
import array 
import random

def parition(arr,from_,to):
    x = arr[to]
    i = from_ - 1 
    j = from_ 
    while j < to:
        
        if arr[j] < x:
            i = i + 1 
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp 

        j = j + 1 
    i = i + 1 
    temp = arr[i]
    arr[i] = arr[to]
    arr[to] = temp 

    return i 

def quikcsort(arr, from_, to):
    if from_ < to:
        q = parition(arr, from_, to)
        quikcsort(arr, from_, q - 1)
        quikcsort(arr, q + 1, to)

if __name__ == '__main__':
    lst = []
    for i in range(0, 20):
        lst.append(random.randint(1, 100))
    arr = array.array('i', lst)
    print(arr)
    quikcsort(arr, 0, 19)
    print(arr)
    
