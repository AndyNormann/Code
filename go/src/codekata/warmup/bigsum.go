package main

import(
    "fmt"
    // "bufio"
    // "io"
    "io/ioutil"
    // "os"
    "strings"
    "strconv"
)

func main() {

    dat, err := ioutil.ReadFile("bigsum.dat")
    if err != nil {
        panic(err)
    }

    file := strings.Split(string(dat), "\n")

    var nums []int64

    for _, elem := range(strings.Split(file[1], " ")) {
        num, err := strconv.ParseInt(elem, 0, 64)
        if err != nil {
            fmt.Printf("Non-number found in file\n")

        }

        nums = append(nums, num)
        fmt.Printf("%s\n", elem)
    }

    var sum int64 = 0

    for _, elem := range(nums) {
        sum += elem
    }

    fmt.Printf("%d\n", sum)
}
