package main

import(
    "fmt"
    "os"
    "strings"
    "strconv"
    "io/ioutil"
)

func main() {
    if len(os.Args) != 2 {
        fmt.Printf("Usage: %s <input_file>\n", os.Args[0])
        os.Exit(-1)
    }

    var(
        n int
        k int
        q int
        array []int
        queries []int
    )

 
    dat, err := ioutil.ReadFile(os.Args[1])
    if err != nil {
        panic(err)
    }

    file := strings.Split(string(dat), "\n")

    first_line := strings.Split(file[0], " ")

    num, _ := strconv.Atoi(first_line[0])
    n = num
    num, _ = strconv.Atoi(first_line[1])
    k = num
    num, _ = strconv.Atoi(first_line[2])
    q = num


    for _, elem := range(strings.Split(file[1], " ")) {
        elem, _ := strconv.Atoi(elem)

        array = append(array, elem)
    }

    for i := 2; i < len(file); i++ {
        elem, _ := strconv.Atoi(file[i])
        queries = append(queries, elem)
    }

    fmt.Printf("%d %d %d\n", n, k, q)
    fmt.Printf("%d %d %d\n", array[0], array[1], array[2])
    fmt.Printf("%d\n%d\n%d\n", queries[0], queries[1], queries[2])


    right_rotate(array)
    for _, elem := range(array) {
        fmt.Printf("%d ", elem)
    }
    fmt.Printf("\n")
}

func right_rotate(array []int, amount int) {
    length := len(array)
    temp := array[length - 1]

    for i := length - 1; i > 0; i-- {
        array[i] = array[i-1]
    }

    array[0] = temp
}
