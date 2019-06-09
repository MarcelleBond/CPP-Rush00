#include <cstdio>
#include <iostream>
#include <chrono>
#include <functional>
#include <curses.h>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"
#include <unistd.h>
int main()
{
    std::srand(time(0));
    int numVillains = rand() % 40 + 20;
    Villain villain[numVillains];
    // WINDOW *vin;
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    int x, y;
    int c;
    noecho();
   // halfdelay(1);
    keypad(stdscr, true);
    curs_set(0);
    raw();
    getmaxyx(stdscr, y, x);
    move(y - 2, x / 2);
    // printw("Write something (ESC to escape): ");
    x = x / 2;
    y = y - 2;
    hero Hero = hero(y, x);
    std::string HeroShip = Hero.getHero();
    printw(HeroShip.c_str());
    int add;
    int shift;
    int VillainY;
    int score = 0;
    for (int i = 1; i <= numVillains; i++)
    {
        VillainY = rand() % 10 + 1;
        add = x + i;
        villain[i] = Villain(VillainY, add);
        // mvprintw(i, 1, "%d\n", villain[i].getX());
        mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
    }
    /////////// START GAME LOOP
    mvprintw(1, 1, "SCORE: %d", score);
    while ((c = getch()) != 27)
    {


        {
           usleep(16666);
           timeout(60);
        }

        shift = std::rand() % 1000;
        if (shift % 3 == 0)
        {

            for (int i = 0; i <= numVillains; i++)
            {
                mvprintw(villain[i].getY(), villain[i].getX(), " ");
                villain[i].setCoordinates(villain[i].getY() + 1, villain[i].getX());
                if (villain[i].getY() == Hero.getY())
                {
                    // delwin(stdscr);
                    mvprintw(10, 10, "GAME OVER");
                    refresh();
                    delay_output(2000);
                    exit(0);
                }
                mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
                // return true;
            }
        }
        if (c == 97)

        {

            /* code */
            mvprintw(Hero.getY() - 1, Hero.getX(), "|");
            if (Hero.Shoot(villain, numVillains))
            {
                mvprintw(1, 1, "SCORE: %d", ++score);
               // mvprintw(40, 109, "PEW PEW");
            }
        }
        if (c == 261)
        {
            mvprintw(Hero.getY() - 1, Hero.getX(), " ");
            mvprintw(y, x, " ");
            move(y, ++x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
        }
        if (c == 260)
        {
            mvprintw(Hero.getY() - 1, Hero.getX(), " ");
            mvprintw(Hero.getY() + 8, Hero.getX(), " ");
            mvprintw(y, x, " ");
            move(y, --x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
        }
        move(10, 0);
        move(0, 0);
        refresh();
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();
}