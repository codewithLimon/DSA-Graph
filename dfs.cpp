#include<bits/stdc++.h>
#include<stack>
using namespace std;

void bfs(vector<int> Graph[], int source, int v){
    stack<int> s;
    int visited_array[v]={0};
    vector<int>visited_sequence;

    s.push(source);

    while(s.empty()==false){
        int top=s.top();
        s.pop();

        if(visited_array[top]==1) continue;
        
        visited_sequence.push_back(top);
        visited_array[top]=1;

        vector<int> cols=Graph[top];

        for(int neighbors : cols){
            s.push(neighbors);
        }

    }

    cout<<"visited array: ";

    for(int x: visited_array){
        cout<<x<<" ";
    }

    cout<<endl;

    cout<<"Visited sequence: ";
    for(int x: visited_sequence){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    // freopen("inputs/ip1.txt","r", stdin);

    int vertices;
    int edges;

    cin>>vertices>>edges;
    vector<int> Graph[vertices];

    for(int i=0;i<edges;i++){
        int from;
        int to;

        cin>>from>>to;

        Graph[from].push_back(to);
        Graph[to].push_back(from);

    }
    int source;
    cin>>source;

    cout<<"Graph traversal: "<<endl;

    for(int i=0;i<vertices;i++){
        cout<<i<<"-->";

        for(int j=0;j<Graph[i].size();j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"DFS: "<<endl;
    bfs(Graph,source,vertices);
}