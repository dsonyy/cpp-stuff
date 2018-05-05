#include "win32-input-manager.h"
#include <cstdio>
#include <allegro5\allegro.h>
#include <SDL.h>

Win32InputManager::Win32InputManager()
{

}


Win32InputManager::~Win32InputManager()
{

}


error Win32InputManager::Init()
{


	return error::EMPTY;
}


void Win32InputManager::Cleanup()
{

}

void Win32InputManager::HandleInput()
{
	//const Uint8* keystate = SDL_GetKeyboardState(NULL);
	//if (keystate[SDL_SCANCODE_LEFT])
	//{
	//	printf("left\n");
	//}
	//if (keystate[SDL_SCANCODE_RIGHT])
	//{
	//	printf("right\n");
	//}
	//if (keystate[SDL_SCANCODE_UP])
	//{
	//	printf("up\n");
	//}
	//if (keystate[SDL_SCANCODE_DOWN])
	//{
	//	printf("down\n");
	//}

}

//LRESULT CALLBACK Win32InputManager::WindowProc(HWND hWnd, UINT msg,
//	WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_KEYDOWN:
//		printf("-----\n");
//		break;
//	case WM_KEYUP:
//		printf("=====\n");
//		break;
//	default:
//		return DefWindowProc(hWnd, msg, wParam, lParam);
//	}
//
//	return 0;
//}