#include <iostream>
#include "actions.h"
#include "agent.h"
#include "environment.h"
#include "maze.h"

using namespace std;


int showMenu(){
    int n;

    cout << "\n1 - run \n";
    cout << "2 - learning \n";
    cout << "3 - exit \n";
    cout << "Enter number: ";
    cin >> n;
    return n;
}

int main(){
    Maze maze = Maze();
    int m;
    do {

        m = showMenu();
        switch (m)
        {
            case 1:
                maze.run();
                maze.nullCountSteps();
                break;
            case 2:
                maze.learning();
                maze.nullCountSteps();
                break;
        }
    }while(m!=3);


    return 0;
}

