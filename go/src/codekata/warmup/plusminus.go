package main

import(
    "fmt"
    "io/ioutil"
    "strconv"
    "strings"
)

func main() {
    dat, err := ioutil.ReadFile("plusminus.dat")
    if err != nil {
        panic(err)
    }

    lines := strings.Split(string(dat), "\n")

    amount, err := strconv.ParseFloat(lines[0], 64)
    if err != nil {
        panic(err)
    }


    var nums []int

    for _, elem := range(strings.Split(lines[1], " ")) {
        current_num, err := strconv.Atoi(elem)
        if err != nil {
            panic(err)
        }

        nums = append(nums, current_num)
    }

    // Fractions
    positive := 0.0
    negative := 0.0
    zero     := 0.0

    for _, elem := range(nums) {
        if elem == 0 {
            zero++
        } else if elem < 0 {
            negative++
        } else if elem > 0 {
            positive++
        }
    }

    positive /= amount
    negative /= amount
    zero /= amount

    fmt.Printf("%f\n%f\n%f\n", positive, negative, zero)

}
