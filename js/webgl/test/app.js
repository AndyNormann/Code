var canvas = document.getElementById('halla');
var gl = canvas.getContext('webgl', {stencil: true});
var shader_program = gl.createProgram();
var color = [
    0, 1, 0, 
    1, 0, 0,
    0, 0, 1
];

function InitDemo() {
    if (!gl) {
        gl = canvas.getContext('experimental-webgl');
    }

    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    let vertices = [
        0.0,  0.5,
        0.5, -0.5,
       -0.5, -0.5
    ];

    init_shaders();

    var color_buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, color_buffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(color), gl.STATIC_DRAW);


    draw_triangles(transform(vertices,  0.5, -0.5));
    draw_triangles(transform(vertices, -0.5, -0.5));
    draw_triangles(transform(vertices,  0.0,  0.5));
}

function transform(vertices, x, y) {
    let new_vertices = [];
    for (let i = 0; i < vertices.length; i += 2) {
        new_vertices[i] = vertices[i] + x;
        new_vertices[i+1] = vertices[i+1] + y;
    }
    return new_vertices;
}

function draw_triangles(vertices) {
    let vertex_buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

    let coord = gl.getAttribLocation(shader_program, "coordinates");
    gl.vertexAttribPointer(coord, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(coord);

    var color_attrib = gl.getAttribLocation(shader_program, "color");
    gl.vertexAttribPointer(color, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(color_attrib);

    gl.drawArrays(gl.TRIANGLES, 0, vertices.length/2);
}


function init_shaders() {
    // Vertex shader
    let vertex_code =
        'attribute vec3 color;' +
        'varying vec3 vColor;' +
        'attribute vec2 coordinates;' +
        'void main(void) {' +
        'gl_Position = vec4(coordinates, 0.0, 1.0);' +
        'vColor = color;' +
        '}';

    let vertex_shader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertex_shader, vertex_code);
    gl.compileShader(vertex_shader);

    // Fragment shader
    let fragment_code = 
        'precision mediump float;' +
        'varying vec3 vColor;' + 
        'void main(void) {' +
        'gl_FragColor = vec4(1.0, 1, 1.0, 1.0);' +
        '}';
    let fragment_shader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragment_shader, fragment_code);
    gl.compileShader(fragment_shader);

    gl.attachShader(shader_program, vertex_shader);
    gl.attachShader(shader_program, fragment_shader);

    gl.linkProgram(shader_program);
    gl.useProgram(shader_program);
}
