import sys
import os
#temporarily add the algorithms/heaps/ to the python path
sys.path.insert(0, os.getcwd()[:-20]+'/Algorithms/Heaps')
from MaxHeapify import constructMaxHeap

class MaxHeap:
    heap = None
    def __init__(self, arr = []):
        constructMaxHeap(arr)
        self.heap = arr

    def getSize(self):
        return len(self.heap)

    def peekMax(self):
        if(self.getSize() > 0):
            return self.heap[0]


def main():
    mHeap = MaxHeap()
    print(mHeap.getSize())
    print(mHeap.peekMax())
    mHeap = MaxHeap([1,2,3,4]) 
    print(mHeap.getSize())
    print(mHeap.peekMax())
    print(mHeap.heap) 

if __name__ == '__main__':
    main()
