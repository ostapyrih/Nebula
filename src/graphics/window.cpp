#include "window.h"

namespace nebula::graphics
{

    Window::Window(const char *name, int width, int height)
    {
        m_Name = name;
        m_Width = width;
        m_Height = height;
        if (!init())
            glfwTerminate();

        for (bool &m_Key : m_Keys)
            m_Key = false;

        for (bool &m_Button : m_Buttons)
            m_Button = false;
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::init()
    {

        if (!glfwInit())
        {
            std::cout << "Error initializing GLFW" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

        if (!m_Window)
        {
            std::cout << "Failed to create window" << std::endl;
            return false;;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, this);
        glfwSetWindowSizeCallback(m_Window, window_resize);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
        glfwSetCursorPosCallback(m_Window, cursor_position_callback);

        if (glewInit() != GLEW_OK)
        {
            std::cout << "Error initializing GLEW" << std::endl;
            return false;
        }

        return true;

    }

    bool Window::closed() const
    {
        return glfwWindowShouldClose(m_Window) == 1;
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update()
    {
        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
            std::cout << "OpenGL Error: " << error << std::endl;

        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool Window::isKeyPressed(unsigned int keycode)
    {
        if (keycode >= MAX_KEYS)
            return false;
        return m_Keys[keycode];
    }

    bool Window::isMouseButtonPressed(unsigned int button)
    {
        if (button >= MAX_BUTTONS)
            return false;
        return m_Buttons[button];
    }

    void Window::getCursorPosition(double &xpos, double &ypos)
    {
        xpos = mx;
        ypos = my;
    }

    void Window::window_resize(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        auto *win = (Window *) glfwGetWindowUserPointer(window);
        win->m_Keys[key] = action != GLFW_RELEASE;
    }

    void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        auto *win = (Window *) glfwGetWindowUserPointer(window);
        win->m_Buttons[button] = action != GLFW_RELEASE;
    }

    void Window::cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
    {
        auto *win = (Window *) glfwGetWindowUserPointer(window);
        win->mx = xpos;
        win->my = ypos;
    }


}