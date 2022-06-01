def constructMaxHeap(arr):
    for k in range(int(len(arr)/2),-1,-1):
        maxHeapify(arr,k)

def maxHeapify(arr, i):
    largest = i
    if(2*(i)+1 < len(arr) and arr[2*(i)+1] > arr[largest]):
        largest = 2*i+1
    if(2*i+2 < len(arr) and arr[2*i+2] > arr[largest]):
        largest = 2*i+2
    if(largest != i):
        arr[i],arr[largest] = arr[largest],arr[i]
        maxHeapify(arr,largest)

def main():
    arr = [1,2,3,4,5,6,7,8,9]
    print(arr)
    maxHeapify(arr,int(len(arr)/2-1))
    print(arr)
    arr = [1,2,3,4,5,6,7,8,9]
    constructMaxHeap(arr)
    print(arr)

if __name__ == '__main__':
    main()
