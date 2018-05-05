#include <cstdlib>
#include <time.h>
#include <curses.h>
#include <thread>
#include <windows.h>
#include <iostream>

//#define TRUE FALSE
//Happy debugging suckers :D


class Firework;

class Player
{
private:

    int x;
    int y;

    int oldx;
    int oldy;

    int points;
    bool isShoting;

public:

    friend void output(Player & p, Firework f[]);

    Player(int y, int x)
    {
        this->y = y;
        this->x = x;

        oldy = y-1;
        oldx = x;

        points = 0;
        isShoting = false;
    }

    up()
    {
        if (y > 0)
        {
            oldx = x;
            oldy = y;
            y--;
        }
    }

    down()
    {
        if (y < 49)
        {
            oldx= x;
            oldy= y;
            y++;
        }
    }

    right()
    {
        if (x < 97)
        {
            oldx = x;
            oldy = y;
            x++;
        }

    }

    left()
    {
        if (x > 1)
        {
            oldx= x;
            oldy= y;
            x--;
        }
    }
    shot()
    {
        isShoting = true;
    }

    void input()
    {
        while (true)
        {
            Sleep(1);
            switch(getch())
            {
            case KEY_RIGHT:
                right();
                break;
            case KEY_LEFT:
                left();
                break;
            case KEY_UP:
                up();
                break;
            case KEY_DOWN:
                down();
                break;
            case '/':
                shot();
                break;
            }
        }
    }
};

class Firework
{
private:

    int y;
    int x;

    int oldy;
    int oldx;

    int side;
    int speed;

    int isLifing;

    friend void output(Player & p, Firework f[]);
    friend void kids(Firework f[]);

public:

    Firework(int y=49, int x=50, int side=1, int speed=200)
    {
        this-> y = y;
        this-> x = x;

        this-> side = side;
        this-> speed = speed;


        isLifing = true;
    }

    void go()
    {
        oldx = x;
        oldy = y;
        if (side==0)
            x--;
        else if (side==2)
            x++;
        y--;

        Sleep(speed);
    }

    void kill()
    {
        isLifing = false;
    }
};

void kids(Firework f[])
{
    while (true)
    {
        if (f[0].isLifing == true)
            f[0].go();
    }
}

void output(Player & p, Firework f[])
{
    while (true)
    {
        mvprintw(0,11,"%d",p.points);

        move(p.oldy, p.oldx);
        if ((inch()=='[')||(inch()==']'))
            printw(" ");
        move(p.oldy, p.oldx+2);
        if ((inch()=='[')||(inch()==']'))
            printw(" ");

        move(p.y, p.x);
        if ((inch()==' ')||(inch()=='['))
            printw("[");
        else if (inch()=='<')
            printw("<");

        move(p.y, p.x+2);
        if ((inch()==' ')||(inch()==']'))
            printw("]");
        else if (inch()=='>')
            printw(">");

        move(f[0].oldy, f[0].oldx);
        if ((inch()=='\\')||(inch()=='|')||(inch()=='/')||(inch()=='<')||(inch()=='>'))
            printw(" ");

        move(f[0].y, f[0].x);
        if((p.y==f[0].y)&&(p.x==f[0].x)&&(f[0].isLifing==true))
            printw("<");
        else if((p.y==f[0].y)&&(p.x+2==f[0].x)&&(f[0].isLifing==true))
            printw(">");
        else if (f[0].isLifing==true)
        {
            if (f[0].side==0)
                printw("\\");
            else if (f[0].side==1)
                printw("|");
            else if (f[0].side==2)
                printw("/");
        }

        if ((p.y==f[0].y)&&(p.x+1==f[0].x)&&(p.isShoting==true)&&(f[0].isLifing==true))
        {
            f[0].isLifing = false;
            move(f[0].y, f[0].x);
            printw(" ");
            p.points+=100;
        }
        p.isShoting=false;
    }
}

int main()
{
    initscr();
    start_color();
    init_pair(1,0,15);
    init_pair(2,12,0);
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr,TRUE);
    resize_term(50, 100);

    Player p0(5,10);
    Firework f0;
    Firework *fire = new Firework[1];
    mvprintw(0,0,"P0 POINTS:");


    mvprintw(10,50,"1. Sprawdz czy okno konsoli ma wym. 100x50.");
    mvprintw(12,50,"2. Zmien pozycje kursora '[ ]' za pom. strzalek.");
    mvprintw(14,50,"3. Wejdz w interakcje z fajerwerkiem '\\' lecacym");
    mvprintw(15,50,"   z dolu ekranu (wejdz w niego)");
    mvprintw(17,50,"4. To na tyle, milej zabawy c:");


    std::thread  tin(&Player::input, &p0);
    std::thread tout(output, std::ref(p0), std::ref(fire));
    std::thread    f(kids, std::ref(fire));

    tin.join();
    tout.join();

    getch();
    endwin();
}
