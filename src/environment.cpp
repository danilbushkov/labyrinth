
#include <fstream>
#include <iostream>
#include "environment.h"


int Environment::isAgentCell(int cell){
    return agentPosition == cell;
}


int Environment::getCountStates(){
    return countStates;
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