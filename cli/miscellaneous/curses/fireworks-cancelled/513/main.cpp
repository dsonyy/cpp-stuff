#include <cstdlib>
#include <time.h>
#include <curses.h>
#include <thread>
#include <windows.h>

class Player
{
private:
    ///////////////// gracz
    int headX;
    int headY;

    int rows;
    int columns;

    bool isLiving;

    ///////////////// klawiszologia
    char up;
    char down;
    char left;
    char right;
    char bang;

public:



    Player(int Y, int X, char u, char d, char l, char r, char b)
    {
        Y = headY;
        X = headX;

        getmaxyx(stdscr, rows, columns);

        isLiving = true;
        up = u;
        down = d;
        left = l;
        right = r;
        bang = b;
    }

    void write()
    {
        attron( COLOR_PAIR( 5 ) );
        move(headY,headX);
        printw("%c",inch());
        printw("%c",inch());
        attroff( COLOR_PAIR( 5 ));
        refresh();
    }

    void spawn(int y,int x)
    {
        headX=x;
        headY=y;
        write();
    }

    movement()
    {
        while (isLiving)
        {
            switch (getch())
            {
            case KEY_RIGHT:
                if (headX+4 <= columns)
                {
                    move(headY,headX+2);
                    if(inch()!=219)
                    {
                        move(headY,headX);
                    printw("%c",inch());
                    printw("%c",inch());
                        headX=headX+2;
                        write();
                    }
                }
                break;

            case KEY_LEFT:
                if (headX-1 > 0)
                {
                    move(headY,headX-2);
                    if(inch()!=219)
                    {
                        move(headY,headX);
                    printw("%c",inch());
                    printw("%c",inch());
                        headX=headX-2;
                        write();
                    }
                }
                break;

            case KEY_UP:
                if (headY > 0)
                {
                    move(headY,headX);
                    printw("%c",inch());
                    printw("%c",inch());
                    headY=headY-1;
                    write();
                }
                break;

            case KEY_DOWN:
                if (headY+1 < rows)
                {
                    move(headY+1,headX);
                    if(inch()!=219)
                    {
                        move(headY,headX);
                    printw("%c",inch());
                    printw("%c",inch());
                        headY=headY+1;
                        write();
                    }
                }
                break;
            case 'a':
                printw("cool");
                break;
            case 'A':
                printw("cool");
                break;
            }
            refresh();
        }
    }
};

class Firework
{
private:
    /////////////////////////  firework 'head' position
    int X;
    int Y;

    /////////////////////////  stick shits
    bool isRight;
    int speed;

    /////////////////////////  'BANG' shits
    bool isExplode;
    int flavour;
    int framerate;
    int color1;
    int color2;

    /////////////////////////  terminal size
    int maxX;
    int maxY;

public:
    Firework(int min_x, int max_x, int how_fast, int bang_type, int frame_rate,int color_first, int color_sec)
    {
        getmaxyx(stdscr, maxY, maxX);

        srand( time( NULL ) );
        X = rand() % max_x;
        Y = maxY;

        if (X > maxX/2)
        {
            isRight=true;
            X--;
            Y--;
        }
        else
        {
            isRight=false;
            X++;
            Y--;
        }

        speed=how_fast;

        flavour=bang_type;
        framerate=frame_rate;
        color1=color_first;
        color2=color_sec;
    }

    void up()
    {
        while (Y > 0)
        {
            ///////////////// przesoniecie patyka
            move(Y,X);
            printw(" ");
            if (isRight==true)
            {
                X--; Y--;
            }
            else
            {
                X++; Y--;
            }
            ///////////////// wypisanie patyka
             move(Y,X);
            if (isRight==true)
                printw("\\");
            else
                printw("/");
            ///////////////// przerwa czasowa
            refresh();
            Sleep(1000);
        }
    }
};


int main()
{
    initscr();
    start_color();
    init_pair(5,0,7);
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr,TRUE);

    Firework f1(59,65,0,0,0,0,0);
    Player p1(10,5,KEY_UP,KEY_DOWN,KEY_LEFT,KEY_RIGHT,'a');
    p1.spawn(5,5);

    std::thread t2(&Firework::up,&f1);
    std::thread t1(&Player::movement,&p1);
    t2.join();
    t1.join();

    getch();
    endwin();
}
