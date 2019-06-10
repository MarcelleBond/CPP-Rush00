
#include <string>
#include "ncurses.h"
#ifndef VILLAIN_HPP
#define VILLAIN_HPP

class Villain
{
private:
    /* data */
    int x;
    int y;
    std::string ship;
public:
    Villain(int y, int x);
    Villain();
    // Villain(Villain const &src);
    // Villain &operator=(Villain const &src);
    ~Villain();
    std::string getVillain();
    
    void setCoordinates(int y, int x);
    int getX();
    int getY();
};

#endif