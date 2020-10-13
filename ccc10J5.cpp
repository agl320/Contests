#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

// Code is messy n trash idc man i tired

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     
    vector<pair<int,int>> adj;
    int nut,gut,but,hut;
    cin >> nut >> gut >> but >> hut;
    
    pair<int,int> s = {nut-1,gut-1};
    pair<int,int> tg = {but-1,hut-1};
    
    //cout << "start: " << nut-1 << "," << gut-1 <<"\n";
    //cout << "end: " << but-1 << "," << hut-1 <<"\n";
    
    queue<pair<int,int>> q;
    map<pair<int,int>,bool> used;
    map<pair<int,int>,int> d;
    
    pair<int,int> u;
    
    q.push(s);
    used[s] = true;

    while (!q.empty()) {
        pair<int,int> v = q.front();
        //cout<<v.first<<","<<v.second<<"\n";
        q.pop();
        
        if(v==tg)
        {
            cout << d[v];
            break;
        }
        
        //cout << "dist:" << d[v]<<" \n"; 

        if(v.first + 2 <= 7) // UP 
        {
            if(v.second + 1 <= 7) // RIGHT
            {
                if (!used[{v.first+2,v.second+1}]) {
                    used[{v.first+2,v.second+1}] = true;
                    q.push({v.first+2,v.second+1});
                    d[{v.first+2,v.second+1}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x+2,y+1]" << v.first+2 << "," << v.second+1 << "\n";
                }
            }
            if(v.second - 1 >= 0) // LEFT
            {
                if (!used[{v.first+2,v.second-1}]) {
                    used[{v.first+2,v.second-1}] = true;
                    q.push({v.first+2,v.second-1});
                    d[{v.first+2,v.second-1}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x+2,y-1]" << v.first+2 << "," << v.second-1 << "\n";
                }
            }
        }
        if(v.first - 2 >= 0) // DOWN
        {
            if(v.second + 1 <= 7) // RIGHT
            {
                if (!used[{v.first-2,v.second+1}]) {
                    used[{v.first-2,v.second+1}] = true;
                    q.push({v.first-2,v.second+1});
                    d[{v.first-2,v.second+1}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x-2,y+1]" << v.first-2 << "," << v.second+1 << "\n";
                }
            }
            if(v.second - 1 >= 0) // LEFT
            {
                if (!used[{v.first-2,v.second-1}]) {
                    used[{v.first-2,v.second-1}] = true;
                    q.push({v.first-2,v.second-1});
                    d[{v.first-2,v.second-1}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x-2,y-1]" << v.first-2 << "," << v.second-1 << "\n";
                }
            } 
        }
        if(v.second + 2 <= 7) // RIGHT
        {
            if(v.first + 1 <= 7) // UP
            {
                if (!used[{v.first+1,v.second+2}]) {
                    used[{v.first+1,v.second+2}] = true;
                    q.push({v.first+1,v.second+2});
                    d[{v.first+1,v.second+2}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x+1,y+2]" << v.first+1 << "," << v.second+2 << "\n";
                }
            }
            if(v.first - 1 >= 0) // DOWN
            {
                if (!used[{v.first-1,v.second+2}]) {
                    used[{v.first-1,v.second+2}] = true;
                    q.push({v.first-1,v.second+2});
                    d[{v.first-1,v.second+2}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x-1,y+2]" << v.first-1 << "," << v.second+2 << "\n";
                }
            } 
        }
        
        if(v.second - 2 >= 0) // LEFT
        {
            if(v.first + 1 <= 7) // UP
            {;
                if (!used[{v.first+1,v.second-2}]) {
                    used[{v.first+1,v.second-2}] = true;
                    q.push({v.first+1,v.second-2});
                    d[{v.first+1,v.second-2}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x+1,y-2]" << v.first+1 << "," << v.second-2 << "\n";
                }
            }
            if(v.first - 1 >= 0) // DOWN
            {
                if (!used[{v.first-1,v.second-2}]) {
                    used[{v.first-1,v.second-2}] = true;
                    q.push({v.first-1,v.second-2});
                    d[{v.first-1,v.second-2}] = d[v] + 1;
                    
                    //cout << v.first << "," << v.second << "[x-1,y-2]" << v.first-1 << "," << v.second-2 << "\n";
                }
            } 
        }
        
    }

}
