class BinaryTreeNode():
    def __init__(self, val=None, left=None, right=None):
        self.val = val;
        self.left = left;
        self.right = right;

class BinaryTree():
    def __init__(self, root=None):
        if(not root):
            self.root = BinaryTreeNode()
        else:
            self.root = root

def main():
    print("Binary Tree")
    root = BinaryTreeNode(0)
    print(root.val)
    binTree = BinaryTree(root)
    print(binTree.root.val)

if __name__ == "__main__":
    main()

# Binary Trees are Trees where each node has only two children, otherwise they inherit all properties
# of Trees such as them not having loops.

# Like Linked Lists, Binary Trees often are used to implement other, more useful Data Structures such 
# as Heaps and Binary Search Trees.

# Some common operations on Binary Trees are: Insert, Delete, and Search.

