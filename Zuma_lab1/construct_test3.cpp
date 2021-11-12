#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ofstream out("03.in");
    out << endl;
    out << 400000 << endl;
    for (int i=0; i<400000; i++){
        out << 0 << ' ';
        if(i%4==0 || i%4==1){
             out << 'A' << endl;
        }
        if(i%4==2 || i%4==3){
             out << 'B' << endl;
        } 
    }
    out.close();
    return 0;
}