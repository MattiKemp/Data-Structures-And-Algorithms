from LinkedList import DoublyLL, DoublyLLNode

class Queue():
    def __init__(self, dll=DoublyLL()):
        self.dll = dll
    
    def __len__(self):
        return len(self.dll)

    def add(self,n):
        self.dll.appendLeft(DoublyLLNode(n))

    def pop(self):
        return self.dll.removeReturnRight().val

    def peek(self):
        return self.dll.end.val

def main():
    print("Queue")
    queue = Queue()
    print('adding "hello" to queue')
    queue.add("hello")
    print('length of queue: ' + str(len(queue)))
    print('adding "Data Structures are awesome!" to queue')
    queue.add("Data Structures are awesome!") 
    print('length of queue: ' + str(len(queue)))
    print('element popped from queue: ' + queue.pop())
    print('length of queue: ' + str(len(queue)))
    print('element popped from queue: ' + queue.pop())
    print('length of queue: ' + str(len(queue)))

if __name__ == "__main__":
    main()

# The Queue Data Structure is a very useful Data Structure that is implemented usually with a Linked List.
# The Queue essentially the same as waiting in a line in real life. You start at the end and slowly work your way
# to the front as people leave the line once they get to the front. 
# Queues behave with First in First out structure.

# Common basic operations: Add, Pop, and Peek. 

# Example of uses: Obviously a waiting queue, Breadth First Search, add more later.

# Benefits: All common operations are O(1). Very Versatile. Only O(n) memory usage, where n is the number of elements in the queue.
# Easy to implement from scratch.

# Cons: Not good for searching behavior; O(n) look up time. 

