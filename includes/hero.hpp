
#include <string>
#include "../includes/Villain.hpp"
#include "../includes/obstacle.hpp"
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
    hero();
    ~hero();
    hero(hero const &src);
    hero & operator=(hero const &src);
    std::string getHero();
    bool Shoot(Villain villain[], int numVillains, obstacle Obstacle[]);
    void setCoordinates(int y, int x);
    int getX();
    int getY();
};



#endif