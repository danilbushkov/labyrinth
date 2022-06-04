#ifndef MAZE_H
#define MAZE_H

class Maze{
    public:
        Maze();
        ~Maze();
        void learning();
        void run();

    private:
        
        Environment *env;
        Agent *agent;
        int countSteps;
        int step();
        void show();

};


#endif