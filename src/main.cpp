#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <curses.h>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"


// void DisplayMove(Villain *villain)
// {
//     for (int i = 0; i < sizeof(villain); i++)
//     {
//         villain[i].VillainMove();
//         /* code */
//     }
// }

//need to move to linux

int main()
{
    std::srand(time(0));
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    int Numvillains = 5;
    Villain villain[Numvillains];
    // WINDOW *vin;
    int x, y;
    int c;
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    raw();
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2);
    // printw("Write something (ESC to escape): ");
    x = x / 2;
    y = y / 2;
    hero Hero = hero(y,x);
    std::string HeroShip = Hero.getHero();
    printw(HeroShip.c_str());
    int add;
    for (int i = 1; i < 6; i++)
    {
        add = x + i;
        villain[i] = Villain(0, add);
        mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
    }
    /////////// START GAME LOOP
    while ((c = getch()) != 27)
    {
        if (c == 97){

                /* code */
                    mvprintw(Hero.getY()-1,Hero.getX(),"|");
                if (Hero.Shoot(villain, Numvillains)){

                    mvprintw(40,109,"PEW PEW");
                }
                else{
                    mvprintw(40,109,"dumbass");
                }

        }
        if (c == 261)
        {
                    mvprintw(Hero.getY()-1,Hero.getX()," ");
            mvprintw(y, x, " ");
            move(y, ++x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
        }
        if (c == 260)
        {
                    mvprintw(Hero.getY()-1,Hero.getX()," ");
            mvprintw(y, x, " ");
            move(y, --x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
        }
        move(10, 0);
        //  printw("Keycode : %d, and the character: %c ", c,c);
        move(0, 0);
        // printw("Write something (ESC to escape): ");

        //timer_start(Di, 1000);
        refresh();
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();
}