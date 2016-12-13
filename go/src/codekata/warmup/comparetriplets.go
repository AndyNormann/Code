package main

import(
    "fmt"
)

func main() {
    triplet1 := []int{5, 6, 7}
    triplet2 := []int{3, 6, 10}

    sum1 := 0
    sum2 := 0

    for it, _ := range(triplet1) {
        if triplet1[it] > triplet2[it] {
            sum1++
        }
        if triplet2[it] > triplet1[it] {
            sum2++
        }
    }

    fmt.Printf("%d %d\n", sum1, sum2)
}
