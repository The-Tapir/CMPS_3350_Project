#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	//glfw initialize and configure
	//-----------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//glfw window creation
	//--------------------
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//When the user resized the window the viewpoint will be adjusted with this
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//glad: load all OpenGL function pointers
	//glad manages function pointers for OpenGL so we initialize GLAD here
	//---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//Telling OpenGL the size of the rendering window
	//First two params set the location of the lower left corner of the window
	//Third and forth are width and height
	glViewport(0, 0, 800, 600);


	//Checks at the start of each loop if GLFW has been told to close
	while (!glfwWindowShouldClose(window))
	{
		//Swaps color buffer
		glfwSwapBuffers(window);
		//Checks for any events being triggered (keyboard, mouse)
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//When the window changes size GLFW calls this function and fills in the arguments
	glViewport(0, 0, width, height);
}
