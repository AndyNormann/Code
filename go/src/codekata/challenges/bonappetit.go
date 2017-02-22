package main

import (
	"fmt"
)

func main() {
	var (
		n        int
		k        int
		nums     []int
		bcharged int
	)

	fmt.Scanf("%d %d", &n, &k)

	nums = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &n[i])
	}

	fmt.Scanf("%d", &bcharged)

	bactual := 0

	for i := range nums {
		if i == k {
			continue
		}
		bactual += nums[i]
	}

	bactual /= 2

	if bactual == bcharged {
		fmt.Printf("Bon Appetit\n")
	} else {
		fmt.Printf("%d\n", bcharged-bactual)
	}
}
