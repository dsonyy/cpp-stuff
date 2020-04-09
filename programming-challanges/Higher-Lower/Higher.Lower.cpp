#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <random>
#include <time.h>

using namespace std;

int main(void)
{
    cout << "-----------------------------------------" << endl;
    cout << "----- Welcome to Higher/Taller Game -----" << endl;
    cout << "-----------------------------------------" << endl;
    cout << " The program will generate the number."    << endl;
    cout << " You must try to guess what's the number." << endl;

    ///////////////////////////////////////////////////////////////////////////// RANGE OF NUMBERS

    int range;

        cout << "-----------------------------------------" << endl;
        cout << " 1. Select a range of numbers:"            << endl;
        cout << "    a) Easy         (1-100)"               << endl;
        cout << "    b) Normal       (1-250)"               << endl;
        cout << "    c) Hard         (1-500)"               << endl;
        cout << "    d) Really Hard  (1-1000)"              << endl;
        cout << "    e) Nightmare    (1-2000)"              << endl;
        cout << "    f) Boring man   (1-5000)"              << endl;
        cout << "    g) Expert       (1-10000)"             << endl;
        cout << "    h) Lucker       (1-20000)"             << endl;
        cout << "    i) Gambler      (1-77777)"             << endl;
        cout << "    j) Cheater      (1-100000)"            << endl;
        cout << "    k) Programmer   (1-200048)"            << endl;
        cout << "    l) Genius       (1-618033)"            << endl;
        cout << "    m) Wizard       (1-1000000)"           << endl;
        cout << "    n) Prophet      (1-10000000)"          << endl;
        cout << "    o) God          (1-100000000)"         << endl;
        cout << "    p) Chuck Norris (1-1000000000)"        << endl;

    do
    {
        switch (getch())
        {
        case 'a':
        case 'A':
            range = 100;
            break;
        case 'b':
        case 'B':
            range = 250;
            break;
        case 'c':
        case 'C':
            range = 500;
            break;
        case 'd':
        case 'D':
            range = 1000;
            break;
        case 'e':
        case 'E':
            range = 2000;
            break;
        case 'f':
        case 'F':
            range = 5000;
            break;
        case 'g':
        case 'G':
            range = 10000;
            break;
        case 'h':
        case 'H':
            range = 20000;
            break;
        case 'i':
        case 'I':
            range = 77777;
            break;
        case 'j':
        case 'J':
            range = 100000;
            break;
        case 'k':
        case 'K':
            range = 200048;
            break;
        case 'l':
        case 'L':
            range = 618033;
            break;
        case 'm':
        case 'M':
            range = 1000000;
            break;
        case 'n':
        case 'N':
            range = 10000000;
            break;
        case 'o':
        case 'O':
            range = 100000000;
            break;
        case 'p':
        case 'P':
            range = 1000000000;
            break;
        default:
            cout << " There is no such option. Try again."      << endl;
            range = 1;
            break;
        }
    } while (range==1);

    ///////////////////////////////////////////////////////////////////////////// START THE GAME

    mt19937 generator(time(NULL));
    uniform_int_distribution<> distro(1, range);

    int number;
    int number_good = distro(generator);
    int higher = 0;
    int lower = range+1;
    int attempt = 0;

    system("cls");

        cout << "-----------------------------------------" << endl;
    do
    {
        cout << " The searched number is:"                  << endl;
        cout << "  - HIGHER than: "     <<      higher      << endl;
        cout << "  - LOWER than:  "     <<      lower       << endl;
        cout << "-----------------------------------------" << endl;
        cout << " Your number is: "                            ;

        attempt++;

        cin >> number;

        system("cls");
        cout << "-----------------------------------------" << endl;

        if (number == number_good)
        {
            cout << " Good! You have guessed the number!" << endl;
            if (attempt==1)
                cout << " Impressive, You needed only one attemp!"<<endl;
            else
                cout << " You needed " << attempt << " attemps!"<<endl;
        }
        else if (number > number_good)
            cout << " Your number is too high!" << endl;
        else if (number < number_good)
            cout << " Your number is too low!"  << endl;

        if ((number > number_good)&&(number < lower))
            lower = number;
        else if ((number < number_good)&&(number > higher))
            higher = number;
        cout << "-----------------------------------------" << endl;
    } while (number != number_good);

}
