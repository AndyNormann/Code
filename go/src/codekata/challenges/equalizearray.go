package main

import (
	"fmt"
)

func main() {
	var (
		A               []int
		n               int
		nums            = make(map[int]int)
		oneOfTheNumbers int
	)

	fmt.Scanf("%d", &n)

	A = make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
		nums[A[i]]++
		oneOfTheNumbers = A[i]
	}

	max := nums[oneOfTheNumbers]
	maxKey := oneOfTheNumbers

	for key, value := range nums {
		if value > max {
			max = value
			maxKey = key
		}
	}

	total := 0

	for key, value := range nums {
		if key == maxKey {
			continue
		}
		total += value
	}

	fmt.Printf("%d\n", total)
}
