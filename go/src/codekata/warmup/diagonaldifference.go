package main

import(
    "fmt"
    "io/ioutil"
    "strings"
    "strconv"
)

func main() {


    // Read the file and extract the amount of lines
    dat, err := ioutil.ReadFile("diagonaldifference.dat")
    if err != nil {
        panic(err)
    }

    lines := strings.Split(string(dat), "\n")

    amount, err := strconv.Atoi(lines[0])
    if err != nil {
        panic(err)
    }


    // Split the raw strings into numbers
    var nums [][]int32
    for i := 1; i < amount+1; i++ {

        line := strings.Split(lines[i], " ")

        var current_nums []int32
        for j := 0; j < amount; j++ {

            num, err := strconv.Atoi(line[j])
            if err != nil {
                panic(err)
            }

            current_nums = append(current_nums, int32(num))
        }

        nums = append(nums, current_nums)
    }


    // Get diagonal sums
    diagonalsum1 := nums[0][0]
    diagonalsum2 := nums[0][amount-1]

    for i := 1; i < amount; i++ {
        diagonalsum1 += nums[i][i]
    }

    for i := 0; i < amount; i++ {
        diagonalsum2 += nums[i][amount-1-i]
    }

    fmt.Printf("%d\n", diagonalsum1 - diagonalsum2)
}
