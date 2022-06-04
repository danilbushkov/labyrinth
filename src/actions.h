#ifndef ACTIONS_H
#define ACTIONS_H

enum actions{
    up = 0,
    down = 1,
    left = 2,
    right = 3
};

struct moveResult
{
    float reward;
    int state;
};



#endif