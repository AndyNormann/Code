package main

import(
    "fmt"
)


type Node struct {
    data int
    left *Node
    right *Node
}

func (n *Node) add(value int) {
    if n.data == value {
        return
    } else if n.data < value {
        if n.left == nil {
            n.left = new(Node)
            n.left.data = value
        } else {
            n.left.add(value)
        }
    } else if n.data > value {
        if n.right == nil {
            n.right = new(Node)
            n.right.data = value
        } else {
            n.right.add(value)
        }
    }
}

func (n *Node) depth() int {
    if n.left == nil && n.right == nil {
        return 1
    }

    var left, right int

    if n.left != nil {
        left = n.left.depth()
    }
    if n.right != nil {
        right = n.right.depth()
    }

    if left > right {
        return left + 1
    } else {
        return right + 1
    }
}

func (n *Node) print() {
    if n.left != nil {
        n.left.print()
    }
    fmt.Printf("%d ", n.data)
    if n.right != nil {
        n.right.print()
    }
}

type BinaryTree struct {
    root *Node
}

func (tree *BinaryTree) add(value int) {
    if tree.root == nil {
        tree.root = new(Node)
        tree.root.data = value
        return
    }

    tree.root.add(value)
}

func (tree *BinaryTree) depth() int {
    max_depth := tree.root.depth()
    return max_depth
}

func (tree *BinaryTree) print() {
    tree.root.print()
    fmt.Printf("\n")
}



func main() {

    tree := BinaryTree{}

    tree.add(5)
    tree.add(1)
    tree.add(3)
    tree.add(7)
    tree.add(9)
    tree.add(20)
    tree.add(2)
    tree.add(12)

    tree.print()
}
