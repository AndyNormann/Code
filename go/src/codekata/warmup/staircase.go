package main

import(
    "fmt"
)

func main() {
    N := 6

    for i := 0; i < N; i++ {
        for j := 0; j < N-i-1; j++ {
            fmt.Printf(" ")
        }

        for j := N-i-1; j < N; j++ {
            fmt.Printf("#")
        }

        fmt.Printf("\n")
    }
}
