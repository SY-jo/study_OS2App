#include "glad/glad.h"
#include "glfw3.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void process_input(GLFWwindow* window);

const char *vertexShaderSource = 
    "#version 440 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos, 1.0);\n"
    "ourColor = aColor;"
    "}\0";

const char *fragShaderSource = 
    "#version 440 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";


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
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3
    };

    //Buffer in GPU?
        //GPU에 생성되는 buffer의 address는 이쪽에서 알 수 없음. 그래서 이런식으로 사용?
        // VBO : Vertex Buffer Object.
        // Buffer object를 생성하고, reference ID 를 VBO에 저장. 디버거로 확인하면 VBO에 '1'이 저장됨
        // Buffer object는 GPU의 RAM에 존재. 하지만 생성된 것 만으로는 opengl context에 포함되어 있지 않음
        // glBind*()를 이용해 context 와 object 를 연결해두면, 그제서야 각종 state-changing, state-using function이 해당 object를 참조하여 동작하게 됨
    GLuint VBO; 
    glGenBuffers(1, &VBO);

    GLuint EBO;
    glGenBuffers(1, &EBO);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        // location = 0 로 vertex shader에서 설정함.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)) );
    glEnableVertexAttribArray(1);


    //Vertex Shader
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

        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // check and call events, then swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
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