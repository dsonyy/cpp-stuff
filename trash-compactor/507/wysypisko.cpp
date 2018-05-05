#include <curses.h>

int main(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(2);
    noecho();

    while(true)
    {
        unsigned char nav = getch();
        switch (nav)
        {
        case 32:
            printw(" ");
            break;
        }
    }

    getch();
    endwin();
}
