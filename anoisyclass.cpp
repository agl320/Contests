#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector < vector < int >>adj; // = {{1},{2,3},{},{},{5},{}}


vector < bool > vstd2;
vector < bool > stack;

bool
is_cycle_util (int v)
{
  if (vstd2[v] == false)
    {
      vstd2[v] = true;
      stack[v] = true;

      vector < int >::iterator i;
      for (i = adj[v].begin (); i != adj[v].end (); ++i)
	{
	  if (!vstd2[*i] && is_cycle_util (*i))
	    {
	      return true;
	    }
	  else if (stack[*i])
	    {
	      return true;
	    }
	}

    }
  stack[v] = false;
  return false;
}

bool
is_cycle ()
{
  vstd2 = vector < bool > (n, false);
  stack = vector < bool > (n, false);

  for (int i = 0; i < n; i++)
    {
      if (is_cycle_util (i))
	{
	  return true;
	}
    }

  return false;
}


int
main ()
{
  ios::sync_with_stdio (false);
  cin.tie (NULL);

  cin >> n;

  adj = vector < vector < int >>(n);

  int nut, a, b;

  cin >> nut;

  for (int i = 0; i < nut; i++)
    {
      cin >> a >> b;
      adj[a - 1].emplace_back (b - 1);
    }


  if (is_cycle ())
    {
      cout << "N";
    }
  else
    {
      cout << "Y";
    }

}
