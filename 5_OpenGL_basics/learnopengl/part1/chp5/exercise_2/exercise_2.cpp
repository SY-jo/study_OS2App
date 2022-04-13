#include "glad/glad.h"
#include "glfw3.h"
#include <iostream>

using std::cout;
using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void process_input(GLFWwindow* window);


int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(500, 500, "JJ", NULL, NULL);
    if(window == NULL)
    {
        cout << "Fail to create a window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout<< "Failed to Initialize GLAD" << endl;
        return -1;
    }
    
    glViewport(0, 0, 200, 200);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    float vertices[] = {
        -0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        -0.25f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.25f, 0.5f, 0.0f
    };

    // Buffer
    GLuint VBO; 
    glGenBuffers(1, &VBO);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    // Buffer2
    GLuint VBO2; 
    glGenBuffers(1, &VBO2);

    GLuint VAO2;
    glGenVertexArrays(1, &VAO2);

    glBindVertexArray(VAO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    



    //Vertex Shader
    const char *vertexShaderSource = "#version 440 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    }

    //Fragment Shader
    const char *fragShaderSource = 
        "#version 440 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.3f, 0.8f);\n"
        "}\0";
    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
    }

    //Linking Compiled Shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        cout << "ERRPR::PROGRAM::LINK_FAILED\n" << infoLog << endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    //rendering loop
    while(!glfwWindowShouldClose(window))
    {
        // input
        process_input(window);

        // rendering commands
        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 3, 3); 
        glBindVertexArray(0);


        // check and call events, then swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}