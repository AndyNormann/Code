package main

import (
    "fmt"
)

func main() {

    // DATA
    var (
        N int
        Strings []string
        Q int
        Queries []string
    )

    // READ INPUT

    fmt.Scanf("%d", &N)

    for i := 0; i < N; i++ {
        var curString string
        fmt.Scanf("%s", &curString)
        Strings = append(Strings, curString)
    }

    fmt.Scanf("%d", &Q)

    for i := 0; i < Q; i++ {
        var curString string
        fmt.Scanf("%s", &curString)
        Queries = append(Queries, curString)
    }

    // EXECUTE QUERIES

    for i := 0; i < Q; i++ {
        num := 0
        for j := 0; j < N; j++ {
            if Queries[i] == Strings[j] {
                num++
            }
        }
        fmt.Printf("%d\n", num)
    }
}
