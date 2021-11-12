#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ofstream out("09.in");
    for (int i=0; i<2048; i++){
        if(i%4==0 || i%4==1){
             out << 'A';
        }
        if(i%4==2 || i%4==3){
             out << 'B';
        } 
    }
    out << "CCDD" << endl;
    out << 1 << endl;
    out << 2050 << ' ' << 'C' << endl;
    out.close();
    return 0;
}