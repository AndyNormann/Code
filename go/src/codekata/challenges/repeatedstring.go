package main

import (
	"fmt"
)

func main() {
	var (
		s           string
		n           int
		amountFound = 0
	)

	fmt.Scanf("%s", &s)
	fmt.Scanf("%d", &n)

	for _, i := range s {
		if i == 'a' {
			amountFound++
		}
	}

	amountFound *= (n / len(s))

	remainder := n % len(s)

	if remainder != 0 {
		for i := 0; i < remainder; i++ {
			if s[i] == 'a' {
				amountFound++
			}
		}
	}

	fmt.Printf("%d\n", amountFound)
}
