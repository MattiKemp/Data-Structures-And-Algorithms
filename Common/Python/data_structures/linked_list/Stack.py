from LinkedList import DoublyLL, DoublyLLNode

class Stack():
    def __init__(self, dll=DoublyLL()):
        self.dll = dll
    
    def __len__(self):
        return len(self.dll)

    def push(self,n):
        self.dll.appendLeft(DoublyLLNode(n))

    def pop(self):
        return self.dll.removeReturnLeft().val

    def peek(self):
        return self.dll.root.val

def main():
    print("Stack")
    stack = Stack()
    print('Adding plate "1" to the stack')
    stack.push("1")
    print('Size of stack: ' + str(len(stack)))
    print('Adding plate "2" to the stack')
    stack.push("2")
    print('Size of stack: ' + str(len(stack)))
    print('Adding plate "3" to the stack')
    stack.push("3")
    print('Size of stack: ' + str(len(stack)))
    
    print('First plate removed: ' + stack.pop())
    print('Second plate removed: ' + stack.pop())
    print('Third plate removed: ' + stack.pop())

if __name__ == "__main__":
    main()

# The Stack Data Structure is commonly implemented with a Linked List and follows a Last In First Out structure.
# Stacks are easy to remember how they work as one can think of a 'stack' of plates sittng on a table. If you want to 
# get the bottom plate you'll have to remove all the plates above it. The first plate you would remove in any situation will
# be the top plate.

# Common uses for stacks are: Making a recursive function iterative by simulating the recursive stack, Depth First Search, add more later.

# Common basic operations: Push, Pop, and Peek.

# Benefits of stacks: all common operations are O(1). They are very easy to implement.
# Cons: not good for searching, O(n) lookup time, where n is the number of elements in the stack.
