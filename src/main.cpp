#include <iostream> 
#include <fstream>
#include "agent.h"
#include "environment.h"

using namespace std;




int main(){

    //init field and qtable
    //menu learning and view
    //free qtable
    Environment env = Environment();
    Agent agent(env.getCountStates());
    agent.saveQTable();
    env.show();

    return 0;
}

