package main

import(
    "fmt"
)

func main() {
    nums := []int{1, 4, 5, 3, 2, 0}

    sum := 0
    for _, elem := range(nums) {
        sum += elem
    }

    fmt.Printf("%d\n", sum)
}
