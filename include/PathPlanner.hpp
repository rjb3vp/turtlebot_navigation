#ifndef PATH_PLANNER
#define PATH_PLANNER

class PathPlanner
{
public:
PathPlanner();
void registerBlockedCenter();

void registerFreeCenter();


void registerBlockedRight();

void registerFreeRight();

void registerBlockedLeft();

void registerFreeLeft();
float getXVelocity();
float getYVelocity();
float getZVelocity();

float getXTurn();
float getYTurn();
float getZTurn();
};
#endif
