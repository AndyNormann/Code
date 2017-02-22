package main

import (
	"fmt"
)

func main() {
	var (
		M      int
		N      int
		R      int
		matrix [][]int
	)

	M = 4
	N = 4
	R = 1

	//fmt.Scanf("%d %d %d", &M, &N, &R)

	matrix = make([][]int, M)

	for i := 0; i < M; i++ {
		matrix[i] = make([]int, N)
		// for j := 0; j < N; j++ {
		//     fmt.Scanf("%d", &matrix[i][j])
		// }
	}

	matrix[0] = []int{1, 2, 3, 4}
	matrix[1] = []int{5, 6, 7, 8}
	matrix[2] = []int{9, 10, 11, 12}
	matrix[3] = []int{13, 14, 15, 16}

	var iterations int

	if M < N {
		iterations = M / N
	} else {
		iterations = N / M
	}

	iterations = 2

	printMatrix(matrix)

	var temp int

	for times := 0; times <= R; times++ {
		for offset := 0; offset < iterations; offset++ {
			temp = matrix[offset][offset]
			for i := offset; i < M-offset-1; i++ {
				matrix[offset][i] = matrix[offset][i+1]
			}
			for i := offset; i < N-offset-1; i++ {
				matrix[i][M-1] = matrix[i+1][M-1]
			}
			for i := M - offset - 1; i > offset; i-- {
				matrix[N-1-offset][i] = matrix[N-1-offset][i-1]
			}
			for i := N - 1 - offset; i > offset+1; i-- {
				matrix[i][offset] = matrix[i-1][offset]
			}
			matrix[offset+1][offset] = temp
			printMatrix(matrix)
		}
	}
}

func printMatrix(matrix [][]int) {
	fmt.Printf("\n")

	for _, i := range matrix {
		for _, j := range i {
			fmt.Printf("%2d ", j)
		}
		fmt.Printf("\n")
	}
}
