#include <string>
#include "../includes/hero.hpp"


hero::hero(int y, int x){
    this->ship = "^";
    this->y = y;
    this->x = x;

}

hero::~hero(){}


bool hero::Shoot(Villain *villain){
    
    for (size_t i = 0; i < 6; i++)
    {
        /* code */
        mvprintw(villain[i].getY() ,villain[i].getX(), " ");
        villain[i].setCoordinates(villain[i].getY() + 1 ,villain[i].getX());
        mvprintw(villain[i].getY(),villain[i].getX(), villain[i].getVillain().c_str());

    }
    
    for (size_t i = 0; i < 6; i++)
    {
        if (villain[i].getX() == this->x){
            mvprintw(villain[i].getY(), villain[i].getX(), " ");
            villain[i].setCoordinates(1,villain[i].getX());
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