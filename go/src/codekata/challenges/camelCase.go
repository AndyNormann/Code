package main

import (
	"fmt"
)

func main() {
	s := ""

	//fmt.Scanf("%s", &s)

	count := 1

	for _, i := range s {
		if i <= 90 && i >= 41 {
			count++
		}
	}

	fmt.Printf("%d\n", count)
}
