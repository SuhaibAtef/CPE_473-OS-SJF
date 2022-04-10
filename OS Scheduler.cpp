#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include "schedulerAlgo.h"

// main() is where program execution begins.
int main() {
    ifstream indata;
    indata.open("in.txt");
    vector <Process> Parr;
    int N,AT,PT;
    indata>>N;
    char n;
    for(int i=0;i<N;i++){
       indata>>n>>AT>>PT;
       Parr.push_back(Process(n,AT,PT)); 
    }
    indata.close();
    SJF(Parr);
    return 0;
}