#include <iostream>
#include "actions.h"
#include "agent.h"
#include "environment.h"
#include "maze.h"


void Maze::run(){
    { 
        show();
    }while(step());
    if(env->isAgentCell(9)){
        show();
        std::cout<<"win"<<std::endl;
    }else{
        std::cout<<"crash"<<std::endl;
    }
}

void Maze::learning(){
    {
        step();
        std::cout << countSteps << std::endl;
    }while(env->isAgentCell(9));

}

int Maze::step(){

    return 0;
}

void Maze::show(){
    std::cout<<countSteps<<std::endl;
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