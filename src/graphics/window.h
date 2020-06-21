#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace nebula::graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window {
	private:
		const char* m_Name;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
		double mx, my; 

	public:
		Window(const char* name, int width, int height);
		~Window();
		bool closed() const;
		void clear() const;
		void update();

		bool isKeyPressed(unsigned int keycode);
		bool isMouseButtonPressed(unsigned int button);
		void getCursorPosition(double& xpos, double& ypos);
		inline int getWidth() const { return m_Width; };
		inline int getHeight() const { return m_Height; };
	
	private:
		bool init();
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void window_resize(GLFWwindow* window, int width, int height);
	};
	
}