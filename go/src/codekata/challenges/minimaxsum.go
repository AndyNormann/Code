package main

import (
	"fmt"
)

func main() {
	nums := [5]int{1, 2, 3, 4, 5}

	// for i := 0; i < 5; i++ {
	// 	fmt.Scanf("%d", &nums[i])
	// }

	min := nums[0] + nums[1] + nums[2] + nums[3]
	max := nums[0] + nums[1] + nums[2] + nums[3]

	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			for k := j + 1; k < len(nums); k++ {
				for l := k + 1; l < len(nums); l++ {
					curNum := nums[i] + nums[j] + nums[k] + nums[l]
					if curNum < min {
						min = curNum
					} else if curNum > max {
						max = curNum
					}
				}
			}
		}
	}

	fmt.Printf("%d %d\n", min, max)
}
