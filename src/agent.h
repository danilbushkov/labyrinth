#ifndef AGENT_H
#define AGENT_H


class Agent{
    public:
        Agent(int countStates);
        ~Agent();
        void saveQTable();

    private:
        float **qtable;
        int countStates;

        void InitQTable();
};

#endif