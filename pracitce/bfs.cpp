#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>graph[], int v, int source){
    queue<int> myQueue;

    int visited_array[v]={0};
    vector<int>visited_sequence;

    myQueue.push(source);

    while(!myQueue.empty()){
        int top=myQueue.front();
        myQueue.pop();

        if(visited_array[top]==1) continue;

        visited_sequence.push_back(top);
        visited_array[top]=1;

        vector<int> neighbors=graph[top];
        for(int x:neighbors){
           if(visited_array[x]==0){
             myQueue.push(x);
           }
        }
    }
    


    cout<<"visited sequence: ";
    for(int x:visited_sequence){
        cout<<x<<" ";
    }
    cout<<endl;
    
    cout<<"visited array: ";
    for(int x:visited_array){
        cout<<x<<" ";
    }
    cout<<endl;

    
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<int>graph[v];

    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;

        graph[from].push_back(to);
    }


    // for(int i=0;i<v;i++){

    //     cout<<i<<"->";
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<"";
    //     }
    //     cout<<endl;
    // }

    int source;
    cin>>source;


    BFS(graph,v,source);
}