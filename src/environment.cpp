
#include <fstream>
#include <iostream>
#include "actions.h"
#include "environment.h"


moveResult Environment::evaluate(actions action){
    moveResult r;
    r.reward = 0;
    int newAgentPosition = agentPosition + stepSize[action];
    
    if((newAgentPosition<0) ||
        (newAgentPosition>99) ||
        ((action == left) && (newAgentPosition%10 == 9)) ||
        ((action == right) && (newAgentPosition%10 == 0))){
            
        
        r.reward = -1;

    }else if((field[newAgentPosition]==-1)){
        r.reward = -1;
    }else if(newAgentPosition == 9){
        //agentPosition = 90;
        r.reward = 1;
    }else{
        agentPosition = newAgentPosition;
    }

    r.state = field[agentPosition];
    return r;
}



int Environment::isAgentCell(int cell){
    return agentPosition == cell;
}

int Environment::getAgentPosition(){
    return agentPosition;
}


int Environment::getCountStates(){
    return countStates;
}

int Environment::getAgentState(){
    return field[agentPosition];
}

void Environment::show(){
    for(int i = 0; i<100; ++i){
        if(i==agentPosition){
                std::cout<<'0';
        }else{
            if(field[i]==-1){
                std::cout<<'1';
            }else{
                std::cout<<' ';
            }
            if((i+1)%10==0){
                std::cout<<'|'<<std::endl;
            }
        }
        
    }
}

Environment::Environment(){
    agentPosition = 90;
    initField();
}

void Environment::initField(){
    int i=0;
    int j=0;
    int cell;
    std::ifstream in("./field.txt");
    if(in.is_open()){
        while(in>>cell){
            if(cell==0){
                field[i]=j++;
            }else{
                field[i]=-1;
            }
            if(i<100){
                ++i;
            }
        }
    }

    in.close();
    countStates=j;
}