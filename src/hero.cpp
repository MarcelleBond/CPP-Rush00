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

bool hero::Shoot(Villain *villain, int numVillains)
{
    //  mvprintw(0 , 0, "dsfsdfdsf");
    int randY;
    for (int i = 0; i <= numVillains; i++)
    {
        if (villain[i].getX() == this->x)
        {
            randY = rand()%5+1;
            mvprintw(villain[i].getY(), villain[i].getX(), " ");
            villain[i].setCoordinates(randY, rand()%150+50);
            mvprintw(villain[i].getY(), villain[i].getX(), villain[i].getVillain().c_str());
            return true;
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