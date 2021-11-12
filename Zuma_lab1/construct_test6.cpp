#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ofstream out("06.in");
    for (int i=0; i<4100; i++){
        if(i%4==0 || i%4==1){
             out << 'A';
        }
        if(i%4==2 || i%4==3){
             out << 'B';
        } 
    }
    out << endl << 2053 << endl;
    for (int i=0; i<2052; i++){
        out << 0 << ' ';
        if(i%4==0 || i%4==1){ 
             out << 'B' << endl;
        }
        if(i%4==2 || i%4==3){
             out << 'A' << endl;
        } 
    }
    
    out << 0 << ' ' << 'Z' << endl;
    out.close();
    return 0;
}