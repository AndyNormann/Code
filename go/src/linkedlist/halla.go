package main

import (
	"fmt"
)

type Node struct {
	data int
	next *Node
}
type LinkedList struct {
	root *Node
}

func (list *LinkedList) add(data int) {
	var temp *Node

	if list.root == nil {
		list.root = &Node{data, nil}
		return
	}

	for temp = list.root; temp.next != nil; temp = temp.next {
	}

	temp.next = &Node{data, nil}
}

func (list *LinkedList) print() {
	if list == nil || list.root == nil {
		return
	}

	fmt.Printf("%d", list.root.data)

	for temp := list.root.next; temp != nil; temp = temp.next {
		fmt.Printf(" -> %d", temp.data)
	}
}

func main() {
	x := LinkedList{}

	x.add(5)
	x.add(1)
	x.add(2)
	x.add(8)

	x.print()
}
