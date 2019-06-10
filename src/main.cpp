#include <cstdio>
#include <iostream>
#include <chrono>
#include <functional>
#include <curses.h>
#include <unistd.h>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"
#include "../includes/obstacle.hpp"
int main()
{
    std::srand(time(0));
    int numVillains = rand() % 40 + 20;
    Villain villain[numVillains];
    obstacle Obstacle[numVillains];
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    int x, y;
    int c;
    noecho();
   // halfdelay(1);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    raw();
    getmaxyx(stdscr, y, x);
    // int max_y = y;
    // int max_x = x;
    move(y - 2, x / 2);
    x = x / 2;
    y = y - 2;
    hero Hero = hero(y, x);
    std::string HeroShip = Hero.getHero();
    printw(HeroShip.c_str());

    int add;
    // int shift;
    int VillainY;
    int score = 0;
     for (int i = 1; i <= numVillains; i++)
    {
        add = x + i;
        Obstacle[i] = obstacle(y-10, add);
        mvprintw(Obstacle[i].getY(), Obstacle[i].getX(), Obstacle[i].getObstacle().c_str());
    }
    for (int i = 1; i <= numVillains; i++)
    {
        VillainY = rand() % 10 + 1;
        add = x + i;
        villain[i] = Villain(VillainY, add);
        mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
    }
     int secondsLeft = 0;
    int seconds = 0;
    int seconds2 = 0;
    int lives = 1;
    /////////// START GAME LOOP
    mvprintw(1, 1, "Lives: %d", lives);
    mvprintw(2, 1, "SCORE: %d", score);
    while ((c = getch()) != 27)
    {


           mvprintw(3,1,"Seconds: %d", seconds);
        mvprintw(4,1,"milli seconds: %d", secondsLeft);
        secondsLeft++;
        napms(1);
        if (secondsLeft == 1000)
        {
            secondsLeft = 0;
            seconds++;
            seconds2++;
        }

        if (seconds2 == 2)
        {
        for (int i = 0; i <= numVillains; i++)
            {
                mvprintw(villain[i].getY(), villain[i].getX(), " ");
                villain[i].setCoordinates(villain[i].getY() + 1, villain[i].getX());
                if (villain[i].getY() == Hero.getY())
                {
                    mvprintw(1, 1, "Lives: %d", --lives);
                    mvprintw(10, 10, "GAME OVER");
                    refresh();
                    delay_output(2000);
                    exit(0);
                }
                mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
            }
           seconds2 = 0;
        }
        if (c == 32)
        {
            mvprintw(Hero.getY() - 1, Hero.getX(), "|");
            if (Hero.Shoot(villain, numVillains, Obstacle))
            {
                mvprintw(2, 1, "SCORE: %d", ++score);
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