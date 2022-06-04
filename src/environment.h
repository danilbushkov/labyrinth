#ifndef ENV_H
#define ENV_H


class Environment{
    public:
        Environment();
        void show();
        int getCountStates();
        int getAgentState();
        int isAgentCell(int cell);

    private:
        int field[100];
        int agentPosition;
        int countStates;
        int stepSize[4] = {-10, 10, -1, 1};

        void initField();

        moveResult evaluate(actions action);

};

#endif