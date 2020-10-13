#include <iostream>
#include <vector>
#include <queue>

// Notes for anyone seeing this for whatever reason:
// I am lazy so I left some unnecessary template variables, such as the variable for distance
// I could have problably used DFS which would allow me to more easily save space when storing distance R,L,D 

using namespace std;

int n;

vector<vector<bool>> visited;

vector<vector<char>> m;
int RC;
queue<int> rq, cq;
int sr=0,sc=0; 

vector<vector<long int>> D,L,R;

int move_ctr = 0, nodes_left = 1, nodes_next = 0;

bool reached_end = false;

vector<int> dr = {+1,0,0};
vector<int> dc = {0,+1,-1};

void print_queue(queue<int> org)
{
    queue<int> q;
    for (int i = 0; i < org.size(); i++)
    {
        q.push(org.front());
        org.pop();
    }
    while (!q.empty())
    {
    cout << q.front() << " ";
    q.pop();
    }
    cout << endl;
}

void explore(int r, int c)
{
    int rr,cc;
    for(int i = 0; i < 3; i++)
    {
        rr=r+dr[i];
        cc=c+dc[i];
        
        // out of bounds
        if(rr < 0 || cc < 0)
            continue;
        if(rr >= RC || cc >= RC)
            continue;
            
        // visited/blocked
        if(m[rr][cc]=='#')
            continue;
        if(visited[rr][cc])
            continue;
        
        switch(i)
        {
            case 0:
                D[rr][cc]=D[r][c]+1;
                R[rr][cc]=R[r][c];
                L[rr][cc]=L[r][c];
                break;
            case 1:
                R[rr][cc]=R[r][c]+1;
                D[rr][cc]=D[r][c];
                L[rr][cc]=L[r][c];
                break;
            case 2:
                L[rr][cc]=L[r][c]+1;
                R[rr][cc]=R[r][c];
                D[rr][cc]=D[r][c];
                break;
        }
        
        rq.push(rr);
        cq.push(cc);
        visited[rr][cc]=true;
        nodes_next++;
    }
}

int solve()
{
    rq.push(sr);
    cq.push(sc);

    visited[sr][sc]=true;
    
    while(rq.size() > 0)
    {
        int r = rq.front();
        int c = cq.front();
        rq.pop();
        cq.pop();
        
        if(r==n-1 && c==n-1) // reached end point (bottom right of grid)
        {
            reached_end = true;
            break;
        }
        explore(r,c);
        nodes_left--;
        if(nodes_left==0)
        {
            nodes_left=nodes_next;
            nodes_next=0;
            move_ctr++;
        }
    }
    if(reached_end)
    {
        return move_ctr;
    }

    
    return -1;
}

int main()
{
    ios::sync_with_stdio (false);
    cin.tie (NULL);
    
    cin >> n;
    
    visited = vector<vector<bool>>(n, vector<bool>(n));
    
    D=vector<vector<long int>>(n,vector<long int>(n));
    R=vector<vector<long int>>(n,vector<long int>(n));
    L=vector<vector<long int>>(n,vector<long int>(n));
    
    RC=n;
    
    string tmp;
    vector<char> vec_input;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        vec_input = vector<char>(tmp.begin(),tmp.end());
        m.push_back(vec_input);
    } 
    
    int j = solve();
    
    if(j != -1)
    {
        // cmath can suck me cok. Screw memory 
        long int n1=D[n-1][n-1],n2=L[n-1][n-1],n3=R[n-1][n-1];
        cout << (n1*n1) + (n2*n2) + (n3*n3);
    }
    else{
        cout << -1;
    }
    
    return 0;
}
