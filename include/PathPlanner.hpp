#ifndef PATH_PLANNER
#define PATH_PLANNER

class PathPlanner
{
public:
PathPlanner();
void registerBlocked();
void registerFree();
float getXVelocity();
float getYVelocity();
float getZVelocity();

float getXTurn();
float getYTurn();
float getZTurn();
};
#endif
