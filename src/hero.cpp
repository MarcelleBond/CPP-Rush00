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

hero::hero(hero const &src)
{
    *this = src;
}

hero &hero::operator=(hero const &src)
{
    if (this != &src)
    {
        *this = src;
    }
    return (*this);
}


bool hero::Shoot(Villain *villain[], int numVillain){
    // for (int i = 0; i < numVillain; i++)
    // {
    //     mvprintw(villain[i]->getY() ,villain[i]->getX(), " ");
    //     villain[i]->setCoordinates(villain[i]->getY() + 1 ,villain[i]->getX());
    //     mvprintw(villain[i]->getY(),villain[i]->getX(), villain[i]->getVillain().c_str());
        
    //     if (this->y == villain[i]->getY()) 
    //     {
    //         getmaxyx(stdscr,y,x);
    //         mvprintw(y / 2, x / 2, " GAME OVER! ");
    //         refresh();
    //         sleep(5);
    //         exit(EXIT_FAILURE);
    //     }
    // }
    for (int i = 0; i < numVillain; i++)
    {
        if (villain[i]->getX() == this->x){
            int x = rand() % 150 + 50;
            mvprintw(villain[i]->getY(), villain[i]->getX(), " ");
            villain[i]->setCoordinates(0, x);
            mvprintw((villain[i]->getY()), x, villain[i]->getVillain().c_str());
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
