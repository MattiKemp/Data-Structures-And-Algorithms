class SinglyLLNode():
    def __init__(self,val=None,next=None):
        self.val = val
        self.next = next

class DoublyLLNode():
    def __init__(self,val=None,prev=None,next=None):
        self.val = val
        self.prev = prev
        self.next = next

#complete later
class SinglyLL():
    def __init__(self, root=None, end=None):
        self.root = root
        self.end = end
        self.size = 0
        if(self.root):
            self.size += 1
        if(self.end):
            self.size += 1

    def __len__(self):
        return self.size

    def append(self, n):
        self.size += 1
        temp = self.root
        self.root = n
        n.next = temp
        if(self.end):
            self.end = n


class DoublyLL():
    def __init__(self, root=None, end=None):
        self.root = root
        self.end = end
        self.size = 0
        if(self.root):
            self.size += 1
        if(self.end):
            self.size += 1

    def __len__(self):
        return self.size

    def appendLeft(self,n):
        self.size += 1
        temp = self.root
        self.root = n
        n.next = temp
        if(temp):
            temp.prev = n
        if(not self.end):
            self.end = n

    def appendRight(self,n):
        self.size += 1
        temp = self.end
        self.end = n
        n.prev = temp
        if(temp):
            temp.next = n
        if(not self.root):
            self.root = n

    def removeLeft(self):
        if(self.root):
            self.size -= 1
            temp = self.root
            self.root = temp.next
            if(self.root):
                self.root.prev = None
            del temp

    def removeRight(self):
        if(self.end):
            self.size -= 1
            temp = self.end
            self.end = temp.prev
            if(self.end):
                self.end.next = None
            del temp

    def removeReturnLeft(self):
        if(self.root):
            self.size -= 1
            temp = self.root
            self.root = temp.next
            if(self.root):
                self.root.prev = None
            temp.next = None
            temp.prev = None
            return temp
        return None

    def removeReturnRight(self):
        if(self.end):
            self.size -= 1
            temp = self.end
            self.end = temp.prev
            if(self.end):
                self.end.next = None
            temp.next = None
            temp.prev = None
            return temp
        return None

def  main():
    print("Singly Linked List")

if __name__ == "__main__":
    main()

#Notes:
# Linked List are commonly implemented either as just nodes or as a container class 
# to assist in ease of use such as looping/keeping track of the first node.

# Linked List are commonly used to implement stack and queue data structures.

# Common tasks to be done on LL are: Sorting, Reversing, Checking for Loops, and Inserting/Removing.

# You can find some of these common tasks implemented in the Algorithms directory
