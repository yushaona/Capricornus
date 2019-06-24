

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
	//��ʼ��glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MACBOOK����Ҫ�ĺ���

	//��������
	GLFWwindow* window = glfwCreateWindow(WNDWIDTH, WNDHEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		//std::cout << "Failed to create GLFW window" << std::endl;
		printf("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	//���ô���Ϊ��ǰ����Ⱦ������
	glfwMakeContextCurrent(window);
	//��ʼ��glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD");
		return -1;
	}
	glViewport(0, 0, WNDWIDTH, WNDHEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		// ����
		processInput(window);
		// ��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);//˫����  --ǰ����ͺ󻺳�  ǰ���帺����ʾ���󻺳帺����ƣ�Ȼ�󽻻�ǰ�󻺳壬ʵ����ʾ������˸��
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}