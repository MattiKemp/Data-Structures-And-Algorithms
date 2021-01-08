from BinaryTree import BinaryTreeNode

class BinarySearchTree():
    def __init__(self, root=None):
        self.root = root

def main():
    print("Binary Search Tree")

if __name__ == "__main__":
    main()

# Binary Search Trees are a more applicable Data Structure compared to the more abstract Tree and Binary Tree. 
# Binary Search Trees are Binary Trees with the property that the left child of a node must have a smaller value than the value of the node
# and the right child of a node must have a larger value than the value of the node. 
# Whether a B.S.T. can have duplicates is usually up to the specific implementation but usually they don't have duplicates.
# If duplicates are allowed they are ususally implemented by having the left child of a node be smaller or equal to the value of the node.

# Common operations on B.S.T.s are: Insert, Delete, and Search. 

# Benefits of a Binary Search Tree: O(h) look up time, where h is the maximum height of the Tree. 
# This means that in a Binary Search Tree that is, or close to, being a complete Tree we get O(log(n)) look up time, where n is the number of nodes 
# However, we can also have O(n) look up time if the Tree's nodes only have one child.


