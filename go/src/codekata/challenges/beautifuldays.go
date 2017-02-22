package main

import (
	"fmt"
)

func main() {
	var (
		from, to, divisor, total int
	)

    // from = 20
    // to = 23
    // divisor = 6
    total = 0
    from = 1
    to = 2000000
    divisor = 45684660

    for i := from; i <= to; i++ {
        num := i
        numRev := reverseNumber(i)

        absDiff := num - numRev
        if absDiff < 0 {
            absDiff *= -1
        }

        if absDiff % divisor == 0 {
            total++
        }
    }
    
    fmt.Printf("%d\n", total)
}

func reverseNumber(num int) int {
    newNum := 0
    for {
        digit := num % 10
        newNum += digit
        num /= 10
        if num == 0 {
            return newNum
        }
        newNum *= 10
    }
}
