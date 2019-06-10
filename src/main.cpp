#include <cstdio>
#include <iostream>
// #include <chrono>
// #include <thread>
#include <functional>
#include <ncurses.h>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"
#include <stdlib.h>


int main()
{
    int secondsLeft = 0;
    int seconds = 0;
    int seconds2 = 0;

    std::srand(time(0));
    int numVillain = 6;
    Villain *villain[numVillain];
    // WINDOW *vin;
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
    int x, y, c, add, score = 0, lives = 1;
    // int c;
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    //raw();
    getmaxyx(stdscr, y, x);
    x = x / 2;
    y = y / 2;
    move(y, x);
    hero Hero = hero(y * 2, x);
    std::string HeroShip = Hero.getHero();
    printw(HeroShip.c_str());
    // int add;
    for (int i = 1; i < numVillain; i++)
    {
        add = x + i;
        int theY = rand() % 10 + 1;
        villain[i] = new Villain(theY, add);
        mvprintw(villain[i]->getY(), villain[i]->getX(), villain[i]->getVillain().c_str());
        
    }
    /////////// START GAME LOOP
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
       if (seconds2 == 1)
       {
           for (int i = 0; i <= numVillain; i++)
            {
                mvprintw(villain[i]->getY() ,villain[i]->getX(), " ");
                villain[i]->setCoordinates(villain[i]->getY() + 1, villain[i]->getX());
                mvprintw(villain[i]->getY(),villain[i]->getX(), villain[i]->getVillain().c_str());
                if (villain[i]->getY() == Hero.getY()) 
                {
                    lives = 0;
                    mvprintw(2, 1, " live: %d", lives);
                    mvprintw(y, x, " GAME OVER!");
                    refresh();
                    sleep(5);
                    exit(EXIT_FAILURE);
                }
            }
            seconds2 = 0;
       }
        mvprintw(2,1,"live: %d", lives);
        if (c == 32){
            mvprintw(Hero.getY() - 1, Hero.getX(), "|");
            if (Hero.Shoot(villain, numVillain)) {
                score += 5;
                mvprintw(1, 1,"score: %d", score);
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
            mvprintw(Hero.getY()-1,Hero.getX()," ");
            mvprintw(y, x, " ");
            move(y, --x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
        }

        //timer_start(Di, 1000);
        refresh();
    }
    /////////// END GAME LOOP
    getch();
    refresh();
    endwin();
}
