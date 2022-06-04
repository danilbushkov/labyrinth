
#include <fstream>
#include <iostream>
#include "actions.h"
#include "environment.h"


moveResult Environment::evaluate(actions action){
    moveResult r;
    r.reward = 0;
    agentPosition = agentPosition + stepSize[action];
    if(((action == up) && (agentPosition<0)) ||
        ((action == down) && (agentPosition>99)) ||
        ((action == left) && (agentPosition%10 == 0)) ||
        ((action == right) && (agentPosition%10 == 9)) ||
        (field[agentPosition]==-1)){
            agentPosition = 90;
            r.reward = -1;
            
    }else if(agentPosition == 10){
        r.reward = 1;
    }

    r.state = field[agentPosition];

    return r;
}



int Environment::isAgentCell(int cell){
    return agentPosition == cell;
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