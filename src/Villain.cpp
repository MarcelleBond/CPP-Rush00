#include <string>
#include "../includes/Villain.hpp"


Villain::Villain(){

}

Villain::Villain(int y, int x){
    this->ship = "V";
    // int x,y;
    // getmaxyx(stdscr,y,x);
    this->x = x;
    this->y = y;

}

Villain::~Villain(){}

int Villain::getX(){
    // mvprintw(50,50, "X: %d", this->x);
    return this->x;
}

int Villain::getY(){
    // mvprintw(40,40, "Y: %d", this->y);
    return this->y;
}
std::string Villain::getVillain(){
    return this->ship;
}

void Villain::setCoordinates(int y, int x){
    this->y = y;
    this->x = x;
}


