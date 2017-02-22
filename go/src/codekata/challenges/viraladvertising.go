package main

import (
	"fmt"
)

func main() {
	var n int
	amount := 5
	total := 0

	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		current := amount / 2
		total += current
		amount = current * 3
	}

	fmt.Printf("%d\n", total)
}
