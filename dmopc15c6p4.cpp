#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

vector<int> parent, ranc;

void make_set(int v) {
    parent[v] = v;
    ranc[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranc[a] < ranc[b])
            swap(a, b);
        parent[b] = a;
        if (ranc[a] == ranc[b])
            ranc[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int input,w,n,k;
    
    cin >> n >> k;
    
    vector<Edge> edges;
    
    for(int i = 0; i < n-1; i++)
    {
        cin >> input;
        
        Edge tmp = 
        {
            i,
            i+1,
            input
        };

        edges.emplace_back(tmp);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(i+k<n)
        {
            Edge tmp =
            {
                i,
                i+k,
                0
            };
            
            edges.emplace_back(tmp);
        }
    }
    
    vector<Edge> result;
    ranc=vector<int>(n);
    parent=vector<int>(n);
    
    for (int i = 0; i < n; i++)
    {
        make_set(i);
    }
    
    sort(edges.begin(), edges.end());
    
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    
    int ballsack = 0;
    
    for(int i = 0; i < result.size(); i++)
    {
        ballsack += result[i].weight;
    }
    
    
    cout << ballsack;

}
