package main

import (
    "fmt"
)

var (
    S string = ""
    History []string
)

func main() {
    fmt.Printf("%balle\n")
}

func delete(num int) {
    S = S[num:len(S)]
}

func append(input string) {
    S = S + input
}

func print(num int) {
    fmt.Printf("%c\n", S[num])
}
