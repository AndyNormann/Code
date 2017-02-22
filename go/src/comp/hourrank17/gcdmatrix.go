package main

import (
    "fmt"
)

func main() {
    var (
        n int
        m int
        q int
        a []int
        b []int
        things [][4]int
        M [][]int
    )

    fmt.Scanf("%d %d %d", &n, &m, &q)

    a = make([]int, n)
    b = make([]int, m)
    things = make([][4]int, q)
    M = make([][]int, n)

    for i := 0; i < n; i++ {
        M[i] = make([]int, m)
    }

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    for i := 0; i < m; i++ {
        fmt.Scanf("%d", &b[i])
    }

    for i := 0; i < q; i++ {
        fmt.Scanf("%d", &things[i][0])
        fmt.Scanf("%d", &things[i][1])
        fmt.Scanf("%d", &things[i][2])
        fmt.Scanf("%d", &things[i][3])
    }

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            M[i][j] = gcd(a[i], b[j])
        }
    }

    for i := 0; i < q; i++ {

        upperX := things[i][0]
        upperY := things[i][1]
        lowerX := things[i][2]
        lowerY := things[i][3]

        nums := make(map[int]int, (lowerX-upperX) * (lowerY-upperY))

        for j := upperX; j < lowerX+1; j++ {
            for k := upperY; k < lowerY+1; k++ {
                nums[M[j][k]] += 1
            }
        }

        fmt.Printf("%d\n", len(nums))
    }
}

func gcd(a, b int) int {
    var bgcd func(a, b, res int) int
 
    bgcd = func(a, b, res int) int {
	switch {
	case a == b:
	    return res * a
	case a % 2 == 0 && b % 2 == 0:
	    return bgcd(a/2, b/2, 2*res)
	case a % 2 == 0:
	    return bgcd(a/2, b, res)
	case b % 2 == 0:
	    return bgcd(a, b/2, res)
	case a > b:
	    return bgcd(a-b, b, res)
	default:
	    return bgcd(a, b-a, res)
	}
    }
 
    return bgcd(a, b, 1)
}
