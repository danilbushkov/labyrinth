#ifndef AGENT_H
#define AGENT_H


class Agent{
    public:
        Agent(int countStates);
        ~Agent();
        void saveQTable();
        actions move();
        void analysis(moveResult m);

    private:
        float **qtable;
        int countStates;
        int state;
        actions action;

        void InitQTable();
        float max(int state);

        const float LF = 0.9;
        const float DF = 0.9;
        

};

#endif