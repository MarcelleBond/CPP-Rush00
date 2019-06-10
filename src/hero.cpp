#include <string>
#include "../includes/hero.hpp"
#include <unistd.h>
hero::hero(int y, int x)
{
    this->ship = "^(-_-* ) ";
    this->y = y;
    this->x = x;
}

hero::~hero() {}

hero::hero(hero const &src){
*this = src;
}

hero &hero::operator=(hero const &src){
    if (this != &src){
        *this = src;
    }
    return (*this);
}

bool hero::Shoot(Villain villain[], int numVillains, obstacle Obstacle[])
{
    int max_x, max_y;
    int randY;

    getmaxyx(stdscr,max_y, max_x);
    for (int i = 0; i <= numVillains; i++)
    {
        if (Obstacle[i].getX() == this->x)
        {
             mvprintw(Obstacle[i].getY(), Obstacle[i].getX(), " ");
             Obstacle[i].setCoordinates(1, 1);
          //  mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
        }
        else{
        if (villain[i].getX() == this->x)
        {
            randY = rand()%5+1;
            mvprintw(villain[i].getY(), villain[i].getX(), " ");
            villain[i].setCoordinates(randY, rand()%max_x+1);
            mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
            return true;
        }
        }
    }
    return false;
}

std::string hero::getHero()
{
    return this->ship;
}

void hero::setCoordinates(int y, int x)
{
    this->y = y;
    this->x = x;
}

int hero::getX()
{
    return this->x;
}

int hero::getY()
{
    return this->y;
}