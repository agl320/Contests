#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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
     
    
    int u,v,n,m;
    
    // unordered_set<int> used;
    
    cin >> n >> m;
    
    vector<int> test = vector<int>(n);
    
    vector<Edge> edges;
    
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        Edge tmp = 
        {
            u-1,
            v-1,
            i
        };
        // used.insert(u);
        // used.insert(v);
        edges.emplace_back(tmp);
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
        //cout << "Edge(" << e.u << "," << e.v << ")\n";
        if (find_set(e.u) != find_set(e.v)) {
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    /*
    
    cout << "\n";
    
    for(int i = 0; i < parent.size(); i++)
    {
        cout << parent[i] << ",";
    }
    
    cout << "\n";
    */
    
    bool dcd = false;
    int check;
    check = parent[0];
    for(int i = 1; i < parent.size(); i++)
    {
        if(check != parent[i])
        {
            cout << "Disconnected Graph";
            dcd = true;
            break;
        }
    }
    
    if(dcd == false)
    {
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i].weight+1 << "\n";
        }
    }
    
    // cout << used.size();
    
    // note: if unused, node will still point to itself
    
}
