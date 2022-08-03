#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<char> adj[N];

int main()
{
    for(int i=0; i<N; i++)
        vis[i] = 0;

    int n,m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    char x,y;
    cout << "Enter the adjacency list: ";
    for(int i=0; i<m ; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<char> q;
    q.push('A');
    vis['A'] = true;
    
    while(!q.empty())
    {
        char node = q.front();
        q.pop();
        cout << node << endl;

        vector<char> :: iterator it;
        for(it = adj[node].begin() ; it != adj[node].end() ; it++)
        {
            if(!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }

}