package main

import (
    "fmt"
)

func main() {
    var (
        q int
        n int
        matrix [][]int
    )

    q = 1
    n = 2

    //fmt.Scanf("%d", &q)

    for i := 0; i < q; i++ {
        //fmt.Scanf("%d", &n)

        matrix = make([][]int, 2*n)

        for j := 0; j < 2*n; j++ {
            matrix[j] = make([]int, 2*n)
        }


        matrix[0] = []int{112, 42, 83, 119}
        matrix[1] = []int{56, 125, 56, 49}
        matrix[2] = []int{15, 78, 101, 43}
        matrix[3] = []int{62, 98, 114, 108}

        // for j := 0; j < 2*n; j++ {
        //     for k := 0; k < 2*n; k++ {
        //         fmt.Scanf("%d", &matrix[j][k])
        //     }
        // }

        total := 0

        if matrix[0][0] + matrix[0][1] > matrix[0][n-1] + matrix[0][n-2] {
            total += matrix[0][0] + matrix[0][1]
        } else {
            total += matrix[0][n-1] + matrix[0][n-2]
        }

        if matrix[1][0] + matrix[1][1] > matrix[1][n-1] + matrix[1][n-2] {
            total += matrix[1][0] + matrix[1][1]
        } else {
            total += matrix[1][n-1] + matrix[1][n-2]
        }

        fmt.Printf("%d\n", total)

    }

    fmt.Printf("Ballanal\n")

}
