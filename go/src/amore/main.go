package main

import (
	"github.com/tanema/amore"
	"github.com/tanema/amore/gfx"
)

func main() {
	amore.Start(update, draw)
}

func update(deltaTime float32) {
}

func draw() {
	gfx.Print("Hello World", 50, 50)
	gfx.Print("Yoyo", 100, 100)
}
