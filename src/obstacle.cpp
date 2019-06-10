#include <string>
#include "../includes/obstacle.hpp"


obstacle::obstacle(){

}

obstacle::obstacle(int y, int x){
    this->rock= "*";
    this->x = x;
    this->y = y;

}

obstacle::~obstacle(){}

obstacle::obstacle(obstacle const &src){
*this = src;
}

obstacle &obstacle::operator=(obstacle const &src){
    if (this != &src){
        *this = src;
    }
    return (*this);
}

int obstacle::getX(){
    return this->x;
}

int obstacle::getY(){
    return this->y;
}
std::string obstacle::getObstacle(){
    return this->rock;
}

void obstacle::setCoordinates(int y, int x){
    this->y = y;
    this->x = x;
}
