package main

import (
    "fmt"
)

func main() {
    var (
        n int
        k int
        h []int
    )

    fmt.Scanf("%d %d", &n, &k)

    h = make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &h[i])
    }

    max := h[0]

    for _, i := range(h) {
        if i > max {
            max = i
        }
    }

    if k > max {
        fmt.Printf("0\n")

    } else {
        fmt.Printf("%d\n", max-k)
    }

}
