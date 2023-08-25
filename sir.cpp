#include<bits/stdc++.h>
using namespace std;

void BFS(vector< int > Graph[], int source, int V)
{
    queue< int > Queue;
    int visited[V] = {0};

    vector< int > visitedSequence;
    Queue.push(source);

    while(Queue.empty()==false)
    {
        int currentlyVisiting = Queue.front();
        Queue.pop();

        if(visited[currentlyVisiting]==1) continue;

        visited[currentlyVisiting] = 1;
        visitedSequence.push_back(currentlyVisiting);

        vector< int > temp = Graph[currentlyVisiting];

        for(int neighbour : temp)
        {
            if(visited[neighbour]==0)
                Queue.push(neighbour);
        }
    }

    cout << "Visited: ";

    for(int i=0; i<V; i++)
        cout << visited[i] << " ";
    cout << endl;


    cout << "Visited Sequence: ";
    for(int x : visitedSequence)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    freopen("inputs/ip1.txt", "r", stdin);

    int V, E; cin >> V >> E;

    vector< int > Graph[V];

    for(int i=1; i<=E; i++)
    {
        int from, to;
        cin >> from >> to;
        Graph[from].push_back(to);
    }

    int source; cin >> source;

    BFS(Graph, source, V);
    return 0;
}