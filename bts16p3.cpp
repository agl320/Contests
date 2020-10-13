#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<double> key = vector<double>(50000);
    int n,ctr=0;
    string x;
    char tmp = '0';
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        x=toupper(x[0]);
        if(x[0]==tmp)
        {
            key[ctr]+=1;
        }
        else
        {
            if(key[ctr]>1)
            {
                ctr += 1;
            }
            if(i!=n-1)
            {
                tmp = x[0];
                key[ctr] = 1;
            }
        }
    }
    
    int total = n;
    for(double u : key)
    {
        if(u==0)
        {
            break;
        }
        total += (u*(u-1)) - (((u-1)/2)*u);
    }
    
    cout << total;
    
    return 0;
}
