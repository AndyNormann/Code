package main

import "fmt"

func main() {

    list := insWeave(11, []int{1, 2, 3, 4})

    for _, elem := range list {
        fmt.Printf("%d\n", elem)
    }
}

func insWeave(weave int, list []int) []int  {

    var retVal []int

    for i := 0; i < len(list); i++ {
        retVal = append(retVal, list[i])
        retVal = append(retVal, weave)
    }

    return retVal
}
