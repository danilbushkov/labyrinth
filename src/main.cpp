#include <iostream> 
#include <fstream>

using namespace std;




int main(){

    //init field and qtable
    //menu learning and view
    //free qtable

    int field[100];
    int cell;

    int i = 0;
    int j = 0;
    ifstream in("./field.txt");
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

    float **qtable = new float*[j];
    for(i = 0; i<j; ++i){
        qtable[i] = new float[4];
    }

    in.open("./qtable.txt");

    if(in.is_open()){
        float k;

        i = 0;
        int m = 0;
        while(in >> k){
            if(i<j){
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





    ofstream out("./qtable.txt");
    
    if(out.is_open()){
        //out << j << endl;
        for(i = 0; i<j; i++){
            
            //out << i << ' ';
            for(int k = 0; k<4; ++k){
                //qtable[i][k] = 0.0;
                out << qtable[i][k] << ' ';
            }
            out << endl;
        }
        
    }
    out.close();

    for(int i = 0; i<j; i++){
        delete [] qtable[i];
    }
    delete [] qtable;


    for(int i = 0; i<100; ++i){
        if(field[i]==-1){
            cout<<'1';
        }else{
            cout<<' ';
        }

        if((i+1)%10==0){
            cout<<'|'<<endl;
        }
    }

    return 0;
}

