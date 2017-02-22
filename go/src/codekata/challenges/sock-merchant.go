package main

import (
	"fmt"
)

func main() {
	var (
		n     int
		c     []int
		freq  = make(map[int]int)
		total int
	)

	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		var num int
		fmt.Scanf("%d", &num)
		c = append(c, num)
	}

	for _, i := range c {
		_, ok := freq[i]
		if ok == false {
			freq[i] = 1
			continue
		}
		freq[i]++
	}

	for _, i := range freq {
		total += (i / 2)
	}

	fmt.Printf("%d\n", total)
}
