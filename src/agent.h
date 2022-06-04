#ifndef AGENT_H
#define AGENT_H


class Agent{
    public:
        Agent(int countStates, int state);
        ~Agent();
        void saveQTable();
        actions move();
        float softmax(float u);
        actions moveSoftmax();
        void analysis(moveResult m);
        void setK(float k);

    private:
        float **qtable;
        int countStates;
        int state;
        actions action;

        void InitQTable();
        float max(int state);

        const float LF = 0.9;
        const float DF = 0.9;
        float K = 0.5;
        

};

#endif