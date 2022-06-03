#include <iostream>
#include <fstream>
#include "agent.h"


Agent::Agent(int countStates){
    this->countStates = countStates;
    qtable = new float*[countStates];
    for(int i = 0; i < countStates; ++i){
        qtable[i] = new float[4];
    }
    InitQTable();
}



Agent::~Agent(){
    for(int i = 0; i<countStates; i++){
        delete [] qtable[i];
    }
    delete [] qtable;
}


void Agent::saveQTable(){
    std::ofstream out("./qtable.txt");
    
    if(out.is_open()){
        for(int i = 0; i<countStates; i++){
            
            for(int k = 0; k<4; ++k){
                out << qtable[i][k] << ' ';
            }
            out << std::endl;
        }
        
    }
    out.close();
}

void Agent::InitQTable(){

    std::ifstream in("./qtable.txt");

    if(in.is_open()){
        float k;

        int i = 0;
        int m = 0;
        while(in >> k){
            if(i<countStates){
                qtable[i][m]=k;
            }
            if(m == 3){
                m = 0;
                ++i;
            }else{
                ++m;
            }
            
        }
    }

    in.close();
}