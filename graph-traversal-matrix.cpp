#include <bits/stdc++.h>
using namespace std;

int main(){
    // take inputs from a file by reading the file 

    freopen("inputs/ip1.txt","r",stdin);

    int vertices;
    int edges;

    cin>>vertices>>edges;

    // get a 2D array for the graph represntation with Vertices X Vertices size

    int Graph[vertices][vertices];

    // initialize the graph array to 0

    memset(Graph,0,sizeof(Graph));

    for(int i=0;i<edges;i++){
        int from,to;
        cin>>from>>to;

        Graph[from][to]=1;
    }


    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }



}