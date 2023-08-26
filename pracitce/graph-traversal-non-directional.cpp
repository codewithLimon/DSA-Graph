#include<bits/stdc++.h>
using namespace std;


void printGraph(vector<int>Graph[], int vertices){
    for(int i=0;i<vertices;i++){
        cout<<i<<"-> ";
        for(int j=0;j<Graph[i].size();j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices;
    int edges;

    cin>>vertices>>edges;

    vector<int> Graph[vertices];


    for(int i=0;i<edges;i++){
        int from;
        int to;

        cin>>from>>to;

        Graph[from].push_back(to);
        // Graph[to].push_back(from);
    }


    printGraph(Graph,vertices);
}