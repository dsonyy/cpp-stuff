#pragma once
#include <windows.h>
#include "input-manager-interface.h"

class Win32InputManager
	: public IInputManager
{
public:
	Win32InputManager();
	~Win32InputManager();

	virtual error Init();
	virtual void Cleanup();

	virtual void HandleInput();

private:
	//LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, 
	//	WPARAM wParam, LPARAM lParam);
};