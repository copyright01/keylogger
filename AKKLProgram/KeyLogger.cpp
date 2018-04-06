#include<Windows.h>
#include <tchar.h>

#define ID_BUTTON1 1
#define ID_BUTTON2 2
#define ID_BUTTON3 3

typedef void(*MYPROC)();

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		CreateWindowEx(0, TEXT("BUTTON"), TEXT("W³acz Keylogger"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 50, 150, 30,
			hwnd, (HMENU)ID_BUTTON1, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindowEx(0, TEXT("BUTTON"), TEXT("Wy³¹cz Keylogger"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 90, 150, 30,
			hwnd, (HMENU)ID_BUTTON2, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindowEx(0, TEXT("BUTTON"), TEXT("Generuj Log"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 130, 150, 30,
			hwnd, (HMENU)ID_BUTTON3, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_BUTTON1:
		{
			HINSTANCE hDll = LoadLibrary(TEXT("KeyLogger"));

			if (hDll != NULL)
			{
				MYPROC Funkcja = (MYPROC)GetProcAddress(hDll, "WlaczHook");
				Funkcja();

			}
			else MessageBox(NULL, TEXT("Nie uda³o siê za³adowaæ biblioteki DLL"), TEXT("B³¹d"), MB_ICONERROR | MB_OK);

			FreeLibrary(hDll);
		}
		break;

		case ID_BUTTON2:
		{
			HINSTANCE hDll = LoadLibrary(TEXT("KeyLogger"));


			if (hDll != NULL)
			{
				MYPROC Funkcja = (MYPROC)GetProcAddress(hDll, "WylaczHook");
				Funkcja();

			}
			else MessageBox(NULL, TEXT("Nie uda³o siê za³adowaæ biblioteki DLL"), TEXT("B³¹d"), MB_ICONERROR | MB_OK);

			FreeLibrary(hDll);
		}
		break;
		case ID_BUTTON3:
		{
			HINSTANCE hDll = LoadLibrary(TEXT("KeyLogger"));

			if (hDll != NULL)
			{
				MYPROC Funkcja = (MYPROC)GetProcAddress(hDll, "GenerujLog");
				Funkcja();
			}
			else MessageBox(NULL, TEXT("Nie uda³o siê za³adowaæ biblioteki DLL"), TEXT("B³¹d"), MB_ICONERROR | MB_OK);

			FreeLibrary(hDll);
		}
		break;

		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = TEXT("KlasaOkien");
	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindow(TEXT("KlasaOkien"), TEXT("Keylogger"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 300, 300, NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


