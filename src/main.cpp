#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <curses.h>
#include <unistd.h>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"


void MoveVillian(Villain *villain)
{
    for (size_t i = 0; i < 6; i++)
    {
        /* code */
        mvprintw(villain[i].getY() ,villain[i].getX(), " ");
        villain[i].setCoordinates(villain[i].getY() + 1 ,villain[i].getX());
        mvprintw(villain[i].getY(),villain[i].getX(), villain[i].getVillain().c_str());

    }
}

void Die(Villain *villain, hero Hero, int x, int score)
{
    for (int i = 0; i < 6; i++)
    {

        if (Hero.getY() == villain[i].getY())
        {
         
            mvprintw(1,x/2,"_______  _______  _______  _______        _______           _______  _______ ");
            mvprintw(2,x/2,"(  ____ \\(  ___  )(       )(  ____ \\      (  ___  )|\\     /|(  ____ \\(  ____ )");
            mvprintw(3,x/2,"| (    \\/| (   ) || () () || (    \\/      | (   ) || )   ( || (    \\/| (    )|");
            mvprintw(4,x/2,"| |      | (___) || || || || (__          | |   | || |   | || (__    | (____)|");
            mvprintw(5,x/2,"| | ____ |  ___  || |(_)| ||  __)         | |   | |( (   ) )|  __)   |     __)");
            mvprintw(6,x/2,"| | \\_  )| (   ) || |   | || (            | |   | | \\ \\_/ / | (      | (\\ (   ");
            mvprintw(7,x/2,"| (___) || )   ( || )   ( || (____/\\      | (___) |  \\   /  | (____/\\| ) \\ \\__");
            mvprintw(8,x/2,"(_______)|/     \\||/     \\|(_______/      (_______)   \\_/   (_______/|/   \\__/");
            mvprintw(9,x/2,"YOUR SCORE IS: %d", score);                                                              
            refresh();
            sleep(6);
            exit(0);
        }
    }
}

//need to move to linux

int main()
{
    std::srand(time(0));
    Villain villain[5];
    // WINDOW *vin;
    
    //initscr();
    wborder(initscr(), '|', '|', '-', '-', '+', '+', '+', '+');
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
        mvprintw(villain[i].getY() + 1, villain[i].getX(), villain[i].getVillain().c_str());
    }

    mvprintw(1,1,"Score: %d", 0);


    /////////// START GAME LOOP
    int score = 0;
    while ((c = getch()) != 27)
    {
        {
            usleep(1666);
            timeout(60);
        }
        

        if (c == 97){

                /* code */
                mvprintw(Hero.getY()-1,Hero.getX(),"|");
                if (Hero.Shoot(villain)){
                    mvprintw(1,1,"Score: %d", score++);
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
            MoveVillian(villain);
        }
        if (c == 260)
        {
                    mvprintw(Hero.getY()-1,Hero.getX()," ");
            mvprintw(y, x, " ");
            move(y, --x);
            Hero.setCoordinates(y, x);
            printw(HeroShip.c_str());
            MoveVillian(villain);
        }
        Die(villain, Hero, x, score);
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