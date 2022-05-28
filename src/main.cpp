#include <iostream> 
#include <fstream>

using namespace std;




int main(){

    int field[100];
    int cell;

    int i = 0;
    int j = 0;
    ifstream f("./field.txt");
    if(f.is_open()){
        while(f>>cell){
            if(cell==0){
                field[i]=0;
            }else{
                field[i]=-1;
            }
            if(i<100){
                ++i;
            }
        }
    }

    f.close();




    for(int i = 0; i<100; ++i){
        if(field[i]==-1){
            cout<<'1';
        }else{
            cout<<' ';
        }

        if((i+1)%10==0){
            cout<<endl;
        }
    }

    return 0;
}

