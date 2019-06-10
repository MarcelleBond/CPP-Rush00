
#include <string>
#include "ncurses.h"
#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

class obstacle
{
private:
    /* data */
    int x;
    int y;
    std::string rock;
public:
    obstacle(int y, int x);
    obstacle();
    obstacle (obstacle const &src);
    obstacle &operator=(obstacle const &src);
    ~obstacle();
    std::string getObstacle();
    
    void setCoordinates(int y, int x);
    int getX();
    int getY();
};

#endif