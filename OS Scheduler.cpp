#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include "schedulerAlgo.h"

// main() is where program execution begins.
int main() {
    vector <Process> Parr;
    int N,AT,PT;
    cin>>N;
    char n;
    for(int i=0;i<N;i++){
       cin>>n>>AT>>PT;
       Parr.push_back(Process(n,AT,PT)); 
    }
    SJF(Parr);
    return 0;
}