package main

import (
    "fmt"
)

func main() {
    var (
        n int
        queries int
        M [][]int
    )

    fmt.Scanf("%d", &queries)
    fmt.Scanf("%d", &n)

    M = make([][]int, n)

    for i := 0; i < n; i++ {
        M[i] = make([]int, n)
    }

    for number := 0; number < queries; number++ {
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                fmt.Scanf("%d", &M[i][j])
            }
        }

        counts := make([]int, n)

        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                counts[i] += M[i][j]
            }
        }

        num := counts[0]
        test := true

        for _, i := range(counts) {
            if i != num {
                test = false
            }
        }

        if test {
            fmt.Printf("Possible\n")
        } else {
            fmt.Printf("Impossible\n")
        }
    }
}
