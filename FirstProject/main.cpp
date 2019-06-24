

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW\glfw3.h>
//#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

#define WNDWIDTH 800
#define WNDHEIGHT 600
int main()
{
	//初始化glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MACBOOK才需要的函数

	//创建窗口
	GLFWwindow* window = glfwCreateWindow(WNDWIDTH, WNDHEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		//std::cout << "Failed to create GLFW window" << std::endl;
		printf("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	//设置窗口为当前的渲染上下文
	glfwMakeContextCurrent(window);
	//初始化glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD");
		return -1;
	}
	glViewport(0, 0, WNDWIDTH, WNDHEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		// 输入
		processInput(window);
		// 渲染指令
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);//双缓冲  --前缓存和后缓冲  前缓冲负责显示，后缓冲负责绘制，然后交换前后缓冲，实现显示又无闪烁感
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}