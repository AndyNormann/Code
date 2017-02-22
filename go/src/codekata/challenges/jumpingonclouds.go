package main

import (
	"fmt"
)

func main() {
	var (
		cloudAmount          int
		clouds               [7]int
		current              = 0
		minimumNunberOfMoves = 0
	)

	cloudAmount = 7
	clouds = [7]int{0, 0, 1, 0, 0, 1, 0}

	// fmt.Scanf("%d", &cloudAmount)
	// clouds = make([]int, cloudAmount)

	// for i := 0; i < cloudAmount; i++ {
	//     fmt.Scanf("%d", &clouds[i])
	// }

	for {
		if current == cloudAmount {
			break
		} else if current+1 == cloudAmount {
			minimumNunberOfMoves++
			break
		} else if clouds[current+1] == 1 {
			current += 2
			minimumNunberOfMoves++
		} else if clouds[current+2] == 1 {
			current += 1
			minimumNunberOfMoves++
		}
	}

	fmt.Printf("%d", minimumNunberOfMoves)
}
