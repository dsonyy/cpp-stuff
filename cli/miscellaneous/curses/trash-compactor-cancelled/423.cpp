#include <curses.h>
#include <windows.h>
#include <time.h>

HANDLE wHnd;
HANDLE rHnd;

void menu()
{

    /* rysownaie menu */
    attron( COLOR_PAIR( 1 ) );
	printw("\n\n\n\t\t             ßßßßßßß                  ÜÜ\n");
	printw("\t\t                Û ÜßßÜ ÜßßÜ Üßßß Û  Û ÛÛÛÛÜ\n");
	printw("\t\t                Û ÛßßÜ ÛßßÛ  ßßÜ ÛßßÛ ßßÛÛÛÛ\n");
	printw("\t\t       ÜÜÜ      ß ß  ß ß  ß ßßß  ß  ß    ÛÛÛÛ\n");
	printw("\t\t      Ü     ÜÜ   Ü Ü   ÜÜ   ÜÜ   ÜÜÜ Ü     ÜÜ   ÜÜ\n");
	printw("\t\t      Û    Û  Û Û Û Û Û  Û ÛÜÜÛ Û    Ûßß  Û  Û ÛÜÜß\n");
	printw("\t\t      ßÜÜÜ ßÜÜß Û ß Û ÛÜÜß Û  Û ßÜÜÜ ßÜÜÜ ßÜÜß Û  Û\n");
	printw("\t\t                      Û\n\n\n\n");
    attron( COLOR_PAIR( 2 ) );
    printw("\t\t    ÛßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßÛ\n");
    printw("\t\t    Û           WITAJ W TRASH COMPACTOR ;)          Û\n");
    printw("\t\t    ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÛ\n");
    printw("\t\t    Û                       Û                       Û\n");
    printw("\t\t    Û  -> Nowa gra          Û     Ust. Domy˜lne     Û\n");
    printw("\t\t    Û     Klawiszologia     Û     Ust. Wˆasne       Û\n");
    printw("\t\t    Û     FAQ               Û                       Û\n");
    printw("\t\t    Û     O grze            Û                       Û\n");
    printw("\t\t    Û     Wyj˜cie           Û                       Û\n");
    printw("\t\t    Û                       Û                       Û\n");
    printw("\t\t    ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n");

    int curY = 18, curX = 23; /* poczatkowa pozycja kursora*/

    do
    {
        switch (getch()) /* zmiana pozycji kursora */
        {
        case KEY_DOWN:
            if ((curY < 22) && !((curY == 19)&&(curX ==47)))
            {
                move(curY,curX);
                printw("  ");
                curY++;
                move(curY,curX);
                printw("->");
            }
            break;

        case KEY_UP:
            if ((curY > 18) && !((curY == 21)&&(curX == 47)))
            {
                move(curY,curX);
                printw("  ");
                curY--;
                move(curY,curX);
                printw("->");
            }
            break;

        case KEY_LEFT:
            if ((curY >=18)&&(curY <= 19)&&(curX==47))
            {
                move(curY, curX);
                printw("  ");
                curY = 18;
                curX = 23;
                move(curY, curX);
                printw("->");
            }
            if ((curY >=21)&&(curY <= 22)&&(curX==47))
            {
                move(curY, curX);
                printw("  ");
                curY = 22;
                curX = 23;
                move(curY, curX);
                printw("->");
            }
            break;
        case KEY_RIGHT:
            if ((curY == 18)&&(curX == 23))
            {
                move(18,23);
                printw("  ");
                move(18,47);
                printw("->");
                curX = 47;
                curY = 18;
            }
            else if ((curY == 22)&&(curX == 23))
            {
                move(22,23);
                printw("  ");
                move(22,47);
                printw("->");
                curX = 47;
                curY = 22;
            }
            break;
        }

        if ((curY == 18) && (curX == 23)) /* podmenu NOWA GRA */
        {
            move(18, 50);
            printw("Ust. Domy˜lne");
            move(19, 50);
            printw("Ust. Wˆasne  ");

            move(21, 50);
            printw("               ");
            move(22, 50);
            printw("               ");
        }
        else if ((curY >= 19)&&(curY <=21 ) && (curX == 23)) /* podmenu PUSTE */
        {
            move(18, 50);
            printw("                ");
            move(19, 50);
            printw("                ");

            move(21, 50);
            printw("               ");
            move(22, 50);
            printw("               ");
        }
        else if (curY == 22) /* podmenu WYJSCIE*/
        {
            move(18, 50);
            printw("Naprawd© chcesz");
            move(19, 50);
            printw("wyj˜† z gry?   ");

            move(21, 50);
            printw("Tak            ");
            move(22, 50);
            printw("Nie            ");
        }
    } while (true);
}

int main(void)
{

    SMALL_RECT windowSize = {0, 0, 89, 34};
    COORD bufferSize = {90, 35};
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    start_color();
    srand( time( NULL ) );
    int color = rand() % 7 + 8;
    init_pair( 1, color, 0 );
    init_pair( 2, 15, 0 );

    menu();
    getch();
    endwin();

}
