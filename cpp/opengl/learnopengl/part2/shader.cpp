
const GLchar *vertex_shader_src =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"\n"
"void main() {\n"
"gl_Position = vec4(position.x, position.y, position.y, 1.0);\n"
"}\n";

const GLchar *fragment_shader_src =
"#version 330 core\n"
"out vec4 color;\n"
"\n"
"void main() {\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";


GLuint init_shader_program(const GLchar* vertex_shader_src, const GLchar* fragment_shader_src)
{
    GLuint vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
    glCompileShader(vertex_shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        printf("Vertex shader failed to compile:\n%s\n", infoLog);
        return -1;
    }

    GLuint fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_src, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        printf("Fragment shader failed to compile:\n%s\n", infoLog);
        return -2;
    }

    GLuint shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        printf("Failed to link program:\n%s\n", infoLog);
        return -3;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader_program;
}
