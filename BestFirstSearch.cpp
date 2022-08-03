#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
vector < vector <pi> > graph;

void addedge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost,y));
    graph[y].push_back(make_pair(cost,x));
}

void best_first_search(int src, int target, int n)
{
    vector <bool> visited(n, false);
    priority_queue < pi, vector <pi>, greater <pi> > pq;
    pq.push(make_pair(0, src));
    int s = src;
    visited[s] = true;
    while(!pq.empty())
    {
        int x = pq.top().second;
        cout << x << " ";
        pq.pop();

        if(x==target) break;

        for(int i=0; i < graph[x].size(); i++)
        {
            if(!visited[graph[x][i].second])
            {
                visited[graph[x][i].second] = true;
                pq.push(make_pair(graph[x][i].first,graph[x][i].second));
            }
        }
    }
}

int main()
{
    int n,m;
    cout<< "Enter the number of vertices and edges: ";
    cin >> n >> m;
    graph.resize(n);
    cout << "Enter the adjacency list and cost: ";
    int x,y,cost;
    for(int i=0; i<m ; i++)
    {
        cin >> x >> y >> cost;
        addedge(x,y,cost);
    }
    int source, target;
    cout << "Enter the source and target: ";
    cin>> source >> target;

    best_first_search(source, target, n);
    return 0;
}