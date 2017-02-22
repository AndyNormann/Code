package main

import (
	"fmt"
)

func main() {
	var (
		N         int
		M         int
		matrix    [][]int
		rotations int
	)

    //fmt.Scanf("%d %d %d", &M, &N, rotations)

    M = 4
    N = 4
    rotations = 1

    matrix = make([][]int, M)
    for i := 0; i < M; i++ {
        matrix[i] = make([]int, N)
    }

    // for i := 0; i < M; i++ {
    //     for j := 0; j < N; j++ {
    //         fmt.Scanf("%d", &matrix[i][j])
    //     }
    // }

    matrix[0] = []int{1, 2, 3, 4}
    matrix[1] = []int{5, 6, 7, 8}
    matrix[2] = []int{9, 10, 11, 12}
    matrix[3] = []int{13, 14, 15, 16}

    first := matrix[0][0]

    for i := 0; i < M-1; i++ {
        matrix[0][i] = matrix[0][i+1]
    }

    for i := 0; i < N-1; i++ {
        matrix[i][M-1]
    }

    printMatrix(matrix)
    fmt.Printf("%d\n", rotations)
}

func printMatrix(matrix [][]int) {
    for _, i := range(matrix) {
        for _, j := range(i) {
            fmt.Printf("%d ", j)
        }
        fmt.Printf("\n")
    }
}
