#include <windows.h>
#include <stdio.h>

// KOLORY KONSOLI:
typedef struct _CONSOLE_SCREEN_BUFFER_INFOEX
{
  ULONG      cbSize;
  COORD      dwSize;
  COORD      dwCursorPosition;
  WORD       wAttributes;
  SMALL_RECT srWindow;
  COORD      dwMaximumWindowSize;
  WORD       wPopupAttributes;
  BOOL       bFullscreenSupported;
  COLORREF   ColorTable[16];
}
CONSOLE_SCREEN_BUFFER_INFOEX, *PCONSOLE_SCREEN_BUFFER_INFOEX;

extern "C" BOOL WINAPI GetConsoleScreenBufferInfoEx
(
  HANDLE hConsoleOutput,
  PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx
);

extern "C" BOOL WINAPI SetConsoleScreenBufferInfoEx
(
  HANDLE hConsoleOutput,
  PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx
);

int main()
{


    CONSOLE_SCREEN_BUFFER_INFOEX bi;
    bi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfoEx(hcon, &bi);

    // Format: 0xbbggrr
    bi.ColorTable[ 0] = 0x000000;
    bi.ColorTable[ 1] = 0x111111;
    bi.ColorTable[ 2] = 0x222222;
    bi.ColorTable[ 3] = 0x333333;
    bi.ColorTable[ 4] = 0x444444;
    bi.ColorTable[ 5] = 0x555555;
    bi.ColorTable[ 6] = 0x666666;
    bi.ColorTable[ 7] = 0x777777;
    bi.ColorTable[ 8] = 0x888888;
    bi.ColorTable[ 9] = 0x999999;
    bi.ColorTable[10] = 0xaaaaaa;
    bi.ColorTable[11] = 0xbbbbbb;
    bi.ColorTable[12] = 0xcccccc;
    bi.ColorTable[13] = 0xdddddd;
    bi.ColorTable[14] = 0xeeeeee;
    bi.ColorTable[15] = 0xffffff;
    DWORD color = 0;
    SetConsoleScreenBufferInfoEx(hcon, &bi);

    //initscr();
    //curs_set(0);

    for (;color < 256;color++)
    {
        SetConsoleTextAttribute(hcon, color);
        printf( "XXXXXXXXXXXXXXXXXX\n" );
    }
    SetConsoleTextAttribute(hcon, 1);


    //getch();
    //endwin();
    return 0;
}
