#include "glad/glad.h"
#include "glfw3.h"
#include <iostream>
#include <cmath>

#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using std::cout;
using std::endl;

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void process_input(GLFWwindow *window);

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "JJ", NULL, NULL);
    if (window == NULL)
    {
        cout << "Fail to create a window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to Initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // lower left
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // lower right
        -0.5f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 1.0f, // upper left
        0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // upper right
    };

    float vertices2[] = {
        -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, -5.0f, -5.0f, // lower left
        1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 5.0f, -5.0f,   // lower right
        -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, -5.0f, 5.0f,   // upper left
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 5.0f, 5.0f,     // upper right
    };

    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3
    };

    // Buffer in GPU
    GLuint VBO;
    glGenBuffers(1, &VBO);
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    GLuint EBO;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // Binding & buffer vertex datda
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Texture
    GLuint texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load the container.jpg
    int height, width, channel;
    unsigned char *img = stbi_load("container.jpg", &width, &height, &channel, 0);
    // unsigned char* img = stbi_load("awesomeface.jpg", &width, &height, &channel, 0);
    if (img == NULL)
    {
        std::cout << "Image Load Error!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(img);

    // 2nd Texture
    GLuint texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load the awesomeface.jpg
    stbi_set_flip_vertically_on_load(true);
    unsigned char* img2 = stbi_load("awesomeface.png", &width, &height, &channel, 0);
    if (img == NULL)
    {
        std::cout << "Image Load Error!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img2);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(img2);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glBindVertexArray(VAO);


    // Shader
    Shader myShader("shader_vertex.glsl", "shader_fragment_ex1.glsl");
    myShader.use();
    myShader.setInt("myTexture1", 0);
    myShader.setInt("myTexture2", 1);
    

    // rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        process_input(window);

        // rendering commands
        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // instead of glUseProgram()
        myShader.use();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // check and call events, then swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}