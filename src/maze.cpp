#include <iostream>
#include <unistd.h>
#include "actions.h"
#include "agent.h"
#include "environment.h"
#include "maze.h"

void Maze::nullCountSteps(){
    countSteps = 0;
}


void Maze::run(){
    agent->setK(1);
    env->setAgentPostiton(90);
    do { 
        show();
        sleep(1);
    }while(step());
    if(env->isAgentCell(9)){
        show();
        std::cout<<"win"<<std::endl;
    }else{
        std::cout<<"crash"<<std::endl;
    }
}

void Maze::learning(){
    agent->setK(1);
    env->setAgentPostiton(90);
    do {
        step();
        std::cout << countSteps << "  "<< env->getAgentPosition() << std::endl;
        if(countSteps%5 == 0){
            agent->saveQTable();
        }
    }while(!env->isAgentCell(9));

}

int Maze::step(){
    countSteps++;
    actions action = agent->moveSoftmax();
    moveResult m = env->evaluate(action);
    agent->analysis(m);
    if(m.reward < 0){
        return 0;
    }
    
    return 1;
}

void Maze::show(){
    std::cout<< "step: "<< countSteps<<std::endl;
    env->show();
    std::cout<<std::endl;
}



Maze::Maze(){
    env = new Environment(); 
    agent = new Agent(env->getCountStates(), env->getAgentState());
}


Maze::~Maze(){
    delete env;
    delete agent;
}