#include <string>
#include "../includes/hero.hpp"
#include "../includes/Villain.hpp"
#include <ncurses.h>

hero::hero(int y, int x){
    this->ship = "^";
     this->y = y;
    this->x = x;

}

hero::~hero(){}


bool hero::Shoot(Villain *villain, int numVillain){
    for (int i = 0; i <= numVillain; i++)
    {
        mvprintw(villain[i].getY() ,villain[i].getX(), " ");
        villain[i].setCoordinates(villain[i].getY()+1 ,villain[i].getX());
        mvprintw(villain[i].getY(),villain[i].getX(), villain[i].getVillain().c_str());
        if (villain[i].getY() == this->y) 
        {
            getmaxyx(stdscr,y,x);
            mvprintw(y / 2, x / 2, " You dead niggah");
            refresh();
            sleep(5);
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i <= numVillain; i++)
    {
        if (villain[i].getX() == this->x){
            mvprintw(villain[i].getY(), villain[i].getX(), " ");
            villain[i].setCoordinates(0,villain[i].getX());
            mvprintw((villain[i].getY()), villain[i].getX(), villain[i].getVillain().c_str());

            return true;
        }
    }
    return false;
}

std::string hero::getHero(){
    return this->ship;
}

void hero::setCoordinates(int y, int x){
    this->y = y;
    this->x = x;
}

int hero::getX(){
    return this->x;
}

int hero::getY(){
    return this->y;
}
