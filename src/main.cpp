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

int main()
{
    std::srand(time(0));
    int numVillains = 5;
    Villain villain[numVillains];

    char mesg[] = "Just a string";
    int row, col;               /* to store the number of rows and *
				                 * the number of colums of the screen */
    initscr();                  /* start the curses mode */
    getmaxyx(stdscr, row, col); /* get the number of rows and columns */
    mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
    mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);

    wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');

    int x, y;
    int c;
    noecho();
    //nodelay(stdscr, true);
    halfdelay(8);
    keypad(stdscr, true);
    curs_set(0);
    raw();
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2);
    // printw("Write something (ESC to escape): ");
    x = x / 2;
    y = y / 2;
    hero Hero = hero(y, x);
    std::string HeroShip = Hero.getHero();
    printw(HeroShip.c_str());
    int add;
    for (int i = 1; i < 6; i++)
    {
        add = x + i;
        villain[i] = Villain(2, add);
        mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
    }

    int randMov;


    /////////// START GAME LOOP
    while ((c = getch()) != 27)
    {
        randMov = rand() % 100;
        if (randMov % 3 == 0){

            for (int i = 0; i <= numVillains; i++)
            {
                /* code */
                mvprintw(villain[i].getY(), villain[i].getX(), " ");
                villain[i].setCoordinates(villain[i].getY() + 1, villain[i].getX());
                if(villain[i].getY() == Hero.getY())
                {
                    mvprintw(0, 0, "YOU DEAD");
                    refresh();
                    delay_output(2000);
                    exit(0);
                }
                mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
            }
        }

        if (c == 97)
        {

            /* code */
            mvprintw(Hero.getY() - 1, Hero.getX(), "|");
            if (Hero.Shoot(villain, numVillains))
            {

                mvprintw(40, 50, "POW POW");
            }
            else
            {
                mvprintw(40, 50, "dumbass");
            }
        }
        if (c == 261)
        {
            int hMax;
            int vMax;
            getmaxyx(stdscr, hMax, vMax);
            if (Hero.getX() < (vMax - 3))
            {
                mvprintw(Hero.getY() - 1, Hero.getX(), " ");
                mvprintw(y, x, " ");
                move(y, ++x);
                Hero.setCoordinates(y, x);
                printw(HeroShip.c_str());
            }
            else
            {
                mvprintw(1, 1, "STOP NIGGER");
            }
        }

        if (c == 260)
        {
            int hMax;
            int vMax;
            getmaxyx(stdscr, hMax, vMax);
            if (Hero.getX() > 2)
            {
                mvprintw(Hero.getY() - 1, Hero.getX(), " ");
                mvprintw(y, x, " ");
                move(y, --x);
                Hero.setCoordinates(y, x);
                printw(HeroShip.c_str());
            }
            else
            {
                mvprintw(1, 1, "STOP NIGGER");
            }
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