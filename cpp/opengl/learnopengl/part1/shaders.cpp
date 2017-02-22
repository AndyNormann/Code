

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

const GLchar *fragment_shader_src2 =
"#version 330 core\n"
"out vec4 color;\n"
"\n"
"void main() {\n"
"color = vec4(1.0f, 1.0f, 0.5f, 1.0f);\n"
"}\n";
