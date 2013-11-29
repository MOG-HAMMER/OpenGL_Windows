
#include <windows.h>
 #include <tchar.h>
#include <GL\gl.h>
#include <GL\glu.h>

HDC hDC = NULL;
HGLRC hRC = NULL;
HWND hWnd = NULL;
HINSTANCE hInstance;

const GLsizei windowWidth = 500;
const GLsizei windowHeight = 500;

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	{
					 PostQuitMessage(0);
	}

	default:
	{
			   return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	}

	return 0;

}

int killWindow(GLvoid)
{
	if (hRC)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(hRC);
		hRC = NULL;
	}
	if (!(hDC && ReleaseDC(hWnd, hDC)))
	{
		return FALSE;
	}
	if (!(hWnd && DestroyWindow(hWnd)))
	{
		return FALSE;
	}

	UnregisterClass(_T("OpenGL"), hInstance);

	return TRUE;
}

BOOL createGLWindow(char *title, int width, int height, int bits)
{
	GLuint PixelFormat;

	WNDCLASS wc;

	DWORD dwExStyle;
	DWORD dwStyle;

	RECT WindowRect;

	WindowRect.left = 0;
	WindowRect.right = width;
	WindowRect.top = 0;
	WindowRect.bottom = height;


	hInstance = GetModuleHandle(NULL);

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("OpenGL");

	RegisterClass(&wc);

	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	dwStyle = WS_OVERLAPPEDWINDOW;

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);

	hWnd = CreateWindowEx(dwExStyle,
		_T("OpenGL"), _T("OpenGL"), dwStyle | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, width, height, NULL, NULL, hInstance, NULL);



	static const PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		bits,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	hDC = GetDC(hWnd);

	PixelFormat = ChoosePixelFormat(hDC, &pfd);

	SetPixelFormat(hDC, PixelFormat, &pfd);

	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);

	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);

	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdSHow)
{
	MSG msg;

	int done = 0;

	if (!createGLWindow("OpenGLDemo", windowWidth, windowHeight, 16))
	{
		//some error code
		killWindow();

		return 0;
	}

	while (!done)
	{
		if (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
	killWindow();

	return (int)(msg.wParam);

}


