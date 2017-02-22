package main

import (
    "fmt"
)

func main() {
    var (
        a1 int
        a2 int
        a3 int

        b1 int
        b2 int
        b3 int

        alice int
        bob int
    )
    fmt.Scanf("%d %d %d", &a1, &a2, &a3)

    fmt.Scanf("%d %d %d", &b1, &b2, &b3)


    if a1 > b1 {
        alice++
    } else if a1 < b1 {
        bob++
    }


    if a2 > b2 {
        alice++
    } else if a2 < b2 {
        bob++
    }

    if a3 > b3 {
        alice++
    } else if a3 < b3 {
        bob++
    }

    fmt.Printf("%d %d\n", alice, bob)
}
