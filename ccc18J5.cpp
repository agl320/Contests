#include <stdio.h> 
#include <stdlib.h> 
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> adj; 

    int n; // number of nodes
    int s = 1; // source vertex
    int c,z; // pages, direction
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        adj.push_back({});
        for(int j = 0; j < c; j++)
        {
            cin >> z;
            adj[i].emplace_back(z);
        }
    }

    queue<int> q;
    vector<bool> used(n, false);
  
    
    q.push(s-1);
    used[s-1] = true;
    vector<int> d(n,1);

    int end = 0,tmp = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(adj[v].size() > 0)
        {
            for (int u : adj[v]) 
            {
                if (used[u-1] == 0)
                {
                    tmp++;
                    used[u-1] = true;
                    q.push(u-1);

                    d[u-1] = d[v] + 1;
                }
            }
        }
        else if(end == 0){
            end = d[v];
        }
    }
    
    if(tmp == n)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "N\n";
    } 

    cout << end;
}
