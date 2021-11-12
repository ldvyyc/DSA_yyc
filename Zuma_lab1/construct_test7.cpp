#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ofstream out("07.in");
    for (int i=0; i<2048; i++){
        if(i%4==0 || i%4==1){
             out << 'A';
        }
        if(i%4==2 || i%4==3){
             out << 'B';
        } 
    }
    for (int i=0; i<2048; i++){
        if(i%4==0 || i%4==1){
             out << 'C';
        }
        if(i%4==2 || i%4==3){
             out << 'D';
        } 
    }
    out << "AAB" << endl;
    out << 3 << endl;
    out << 3072 << ' ' << 'D' << endl;
    out << 2048 << ' ' << 'D' << endl;
    out << 2048 << ' ' << 'A' << endl;
    out.close();
    return 0;
}