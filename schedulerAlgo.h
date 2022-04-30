#include <bits/stdc++.h>
using namespace std;
class Process{
    private:
    char Pname;
    int ParrivingTime;
    int PprocessTime;
    int EndTime;
    int StartTime;
    int TurnAroundTime;
    public:
    Process( char name,int arrivingTime,int processTime){
        Pname=name;
        ParrivingTime=arrivingTime;
        PprocessTime=processTime;
    }

    char getName(){
        return Pname;
    }

    int getAT(){
        return ParrivingTime;
    }

    int getPT(){
        return PprocessTime;
    }
    void setEndTime(int z){
        EndTime=z;
        StartTime=EndTime-PprocessTime;
    }
    int cResponseTime(){
        return (StartTime-ParrivingTime);
    }
    int cTurnaroundTime(){
        TurnAroundTime=EndTime-ParrivingTime;
        return (TurnAroundTime);
    }
    int cDelay(){
        return (TurnAroundTime-PprocessTime);
    }
};

bool compareProcessAT( Process& P1,  Process& P2)
{
        return (P1.getAT() < P2.getAT());
}

bool compareProcessPT( Process& P1,  Process& P2)
{
        return (P1.getPT() < P2.getPT());
}
vector<Process> getAns(unordered_set<char> const &s,vector<Process> Parr)
{   
    vector<Process> ans;
    for (auto it = s.begin(); it != s.end(); ++it){
        for (auto i = Parr.begin(); i != Parr.end(); ++i){
        if(*it==(*i).getName()){
            ans.push_back(*i);
            break;
        }
        }
    }
    return(ans);
}

/* Fifo Scheduling for testing purpose's only 
void Fifo (vector<Process> Parr)
{   
    sort(Parr.begin(),Parr.end(),compareProcessAT);
    string orderList="";
    for (auto i = Parr.begin(); i != Parr.end(); ++i){
        orderList+=(*i).getName();
    }
    cout<< orderList<<endl;
}
*/

void SJF(vector<Process> Parr)

{   unordered_set <char> s; //unordered_set for the solution of the algorithm;
    vector<int> endTimes;   //endTimes to hold the values of endTime :we don't need one for startTime because of how SJF works.
    sort(Parr.begin(),Parr.end(),compareProcessAT); //Sorting the vector array based on the arriving time.
    
    string orderList=""; //the first line output.
    //int z =0;
    int z =Parr[0].getAT(); // time or endTime summation variable. or you can say a summation of process times.
    
    // this is how SJF works //

    while(s.size()<Parr.size()){

    vector<Process> vec; 
    //a loop to get all process from the first until first + z time 
    for (auto i = Parr.begin(); (*i).getAT() <= z; ++i){
        if(vec.size()<Parr.size()){
        vec.push_back((*i));
        if(vec.size()==s.size()&&(*(i+1)).getAT()>z)
            z++;
        }else{
            
            break;
        }
    }
    //we sort the vector based on Process Time so we can choose the smallest.
    sort(vec.begin(),vec.end(),compareProcessPT);
    //we add every process in the solution to the set //no replicates would be allowed by using sets.
    for (auto i = vec.begin(); i != vec.end(); ++i){
        if(s.find((*i).getName())==s.end()){
            
            s.insert((*i).getName());
            z+=(*i).getPT();
            endTimes.push_back(z);
            //cout<< z<<endl; //for debugging purposes only.
            break;
        }
    }
    
    }
    vector<Process> ansVec=getAns(s,Parr); // turn set to vector. 

    /* iterate throught the vector to set endTimes*/
    auto j = endTimes.begin();
    for (auto i = ansVec.end()-1; i != ansVec.begin()-1; --i){
        orderList+=(*i).getName();
        //cout<<*j<<endl;
        (*i).setEndTime(*j);
        ++j;
    }
    /*printing the solution*/
    ofstream myfile;
    myfile.open("out.txt");
    myfile<<orderList<<endl;
    sort(ansVec.begin(),ansVec.end(),compareProcessAT);
    for (auto i = ansVec.begin(); i != ansVec.end(); ++i){
        myfile<<(*i).getName()<<": (response="<<(*i).cResponseTime()<<", turnaround="<<(*i).cTurnaroundTime()<<", delay="<<(*i).cDelay()<<")"<<endl;
    }
    myfile.close();
}