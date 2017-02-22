package main

import (
    "fmt"
)

func main() {
    var (
        S string
        total = 0
    ) 

    fmt.Scanf("%s", &S)

    for i := 0; i < len(S); i += 3 {
        if S[i] != 'S' {
            total++
        }
        if S[i+1] != 'O' {
            total++
        }
        if S[i+2] != 'S' {
            total++
        }
    }

    fmt.Printf("%d\n", total)
}
