#include "glad/glad.h"
#include "glfw3.h"
#include <iostream>
#include <cmath>
#include "Shader.h"

using std::cout;
using std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void process_input(GLFWwindow* window);

#define WINDOW_HEIGHT   500
#define WINDOW_WIDTH    500

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "JJ", NULL, NULL);
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
    
    glViewport(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH);
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
    GLuint VBO; 
    glGenBuffers(1, &VBO);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // location = 0 로 vertex shader에서 설정함.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    //Shader
    Shader myShader("D:/J/1_study/5_OpenGL_basics/learnopengl/part1/chp6/shader_vertex_exercise_3.txt",
    "D:/J/1_study/5_OpenGL_basics/learnopengl/part1/chp6/shader_fragment_exercise_3.txt");


    //rendering loop
    while(!glfwWindowShouldClose(window))
    {
        // input
        process_input(window);

        // rendering commands
        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //instead of glUseProgram()
        myShader.use();

        float time = glfwGetTime();
        myShader.setFloat("offset_horizon", sin(time));
        glDrawArrays(GL_TRIANGLES, 0, 3);

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