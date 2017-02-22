#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shaders.cpp"

//
// Function signatures
//
void key_callback(GLFWwindow *window, int key, int scancode, int action,
        int mode);
GLFWwindow *setup_glfw_and_window();
GLuint setup_shader_program();

int drawing_mode = 0;

GLuint shader_program;
GLuint shader_program2;

int main() {

    GLFWwindow *window = setup_glfw_and_window();
    if (!window) {
        printf("Failed to create glfw window\n");
        return -1;
    }

    setup_shader_program();

    if (shader_program == -1) {
        printf("Failed to compile shader program\n");
        return -1;
    }

    //
    // Vertex Buffer Object
    //

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Upper left 
        -0.5f, 0.5f, 0.0f, // Lower left

        0.0f, -0.5f, 0.0f, // Lower middle
        0.5f, 0.5f, 0.0f, // Lower Right

        0.5f, -0.5f, 0.0f // Upper Right
    };

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 4
    };

    GLuint VBO, VAO, EBO;
    GLuint VBO2, VAO2, EBO2;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    // glGenBuffers(1, &EBO2);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3, indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3, indices+(sizeof(GLuint)*3), GL_STATIC_DRAW);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


    glBindVertexArray(VAO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, vertices+(sizeof(GLfloat)*6), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    //
    // Main loop
    //

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Rendering goes here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        if (drawing_mode == 0) {
            glUseProgram(shader_program);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glUseProgram(shader_program2);
        }

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(VAO2);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


        glfwSwapBuffers(window);
    }

    //
    // Cleanup
    //

    glDeleteVertexArrays(1, &VBO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
        int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    } else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        if (drawing_mode == 0) {
            drawing_mode = 1;
        } else {
            drawing_mode = 0;
        }
    }
}

GLFWwindow *setup_glfw_and_window() {
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW"
            << "\n";
        return nullptr;
    }

    // Had to set FORWARD_COMPAT to make it work on OSX
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    //
    // Window setup
    //

    GLFWwindow *window =
        glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window"
            << "\n";
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW"
            << "\n";
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Register key handling callback
    glfwSetKeyCallback(window, key_callback);

    return window;
}

GLuint setup_shader_program() {
    // Vertex Shader

    GLuint vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
    glCompileShader(vertex_shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "Vertex shader could not compile " << infoLog << "\n";
        return -1;
    }

    // Fragment Shader

    GLuint fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_src, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "Fragment shader could not compile: " << infoLog << "\n";
        return -1;
    }

    GLuint fragment_shader2;
    fragment_shader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader2, 1, &fragment_shader_src2, NULL);
    glCompileShader(fragment_shader2);

    glGetShaderiv(fragment_shader2, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader2, 512, NULL, infoLog);
        std::cout << "Fragment shader could not compile: " << infoLog << "\n";
        return -1;
    }

    // Shader Program

    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        std::cout << "Program could not link: " << infoLog << "\n";
        return -1;
    }


    shader_program2 = glCreateProgram();

    glAttachShader(shader_program2, vertex_shader);
    glAttachShader(shader_program2, fragment_shader2);
    glLinkProgram(shader_program2);

    glGetProgramiv(shader_program2, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program2, 512, NULL, infoLog);
        std::cout << "Program could not link: " << infoLog << "\n";
        return -1;
    }

    glUseProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader_program;
}
