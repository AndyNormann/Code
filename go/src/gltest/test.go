package main

import (
	"github.com/go-gl/glfw/v3.2/glfw"
)

func main() {
	err := glfw.Init()
	if err != nil {
		panic(err)
	}

	glfw.WindowHint(glfw.ContextVersionMajor, 3)
	glfw.WindowHint(glfw.ContextVersionMinor, 3)
	glfw.WindowHint(glfw.OpenGLProfile, glfw.OpenGLCoreProfile)
	glfw.WindowHint(glfw.Resizable, glfw.False)

	window, err := glfw.CreateWindow(800, 600, "Wakkaflow", nil, nil)
	if err != nil {
		glfw.Terminate()
		panic(err)
	}

}
