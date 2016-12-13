package main

import (
	"fmt"
	"os"
)

type kangaroo struct {
	pos      int
	velocity int
}

func (this *kangaroo) move() {
	this.pos += this.velocity
}

func main() {
	var (
		kangaroo1 kangaroo
		kangaroo2 kangaroo
	)

	for {
		if kangaroo1.pos == kangaroo2.pos {
			fmt.Printf("YES\n")
			break
		}

		kangaroo1.move()
		kangaroo2.move()
	}
}
