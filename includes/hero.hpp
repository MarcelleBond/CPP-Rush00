
#include <string>
#include "../includes/Villain.hpp"
#ifndef HERO_HPP
#define HERO_HPP

class hero
{
private:
    /* data */
    std::string ship;
    int x;
    int y;
public:
    hero(int y, int x);
    ~hero();
    std::string getHero();
    bool Shoot(Villain *villain, int numVil);
    void setCoordinates(int y, int x);
    int getX();
    int getY();
};



#endif