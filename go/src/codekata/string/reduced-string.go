package main

import (
    "fmt"
)

func main() {
    var input string

    fmt.Scanf("%s", &input)

    out := reduceString(input)

    fmt.Printf("%s\n", out)
}

func reduceString(input string) string {
    if len(input) == 0 {
        return "EMPTY STRING"
    }

    done := false

    for done != true {
        done = true
        for i := 0; i < len(input) - 1; i++ {
            if input[i] == input[i+1] {
                input = input[0:i] + input[i+2:len(input)]
                done = false
            }
        }
    }
    if len(input) == 0 {
        return "EMPTY STRING"
    }
    return input
}
